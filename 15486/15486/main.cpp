#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct Counsel
{
    int T;
    int P;
};

int N,result = 0;
vector<Counsel> v;
int dp[1 << 21] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> N;
    
    v = vector<Counsel>(N+2,{0,0});
    
    for(int i = 1; i <= N; i++)
    {
        int t,p;
        cin >> t >> p;
        v[i] = {t,p};
    }
    
    for(int i = 1; i <= N + 1; i++)
    {
        result = max(result,dp[i]);
        if (i + v[i].T > N + 1)
            continue;
            
        dp[i+v[i].T] = max(result+v[i].P,dp[i+v[i].T]);
    }

    cout << result << '\n';
    return 0;
}
