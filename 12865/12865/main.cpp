#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 100001
#define INF 987654321

using namespace std;

struct Item
{
    int W;
    int V;
};

int N,K;
int dp[MAX] = {0,};
vector<Item> item;

bool comp(const Item& i1, const Item& i2) { return i1.W < i2.W; }

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int w,v;
        cin >> w >> v;
        //dp[w] = v;
        item.push_back({w,v});
    }
    
    sort(item.begin(),item.end(),comp);
    for(int i = 0; i < N; i++)
    {
        for(int j = K; j >= item[i].W; j--)
        {
            dp[j] = max(dp[j],dp[j-item[i].W]+item[i].V);
        }
    }
    
    cout << dp[K] << '\n';
    return 0;
}
