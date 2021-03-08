#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Card
{
    int left;
    int right;
};

int N;
vector<Card> card;
int dp[2001][2001]; // 점수 저장

int DFS(int l,int r) // 버려진 왼쪽 카드의 개수 , 오른쪽 카드의 개수
{
    if(l >= N || r >= N)
        return 0;
    
    int& ret = dp[l][r];
    if(ret != -1)
        return ret;
    
    int case1 = DFS(l+1,r);
    int case2 = DFS(l+1,r+1);
    int case3 = 0;
    if(card[l].left > card[r].right)
        case3 = DFS(l,r+1)+card[r].right;
    
    return dp[l][r] = max(case1,max(case2,case3));
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int l;
        cin >> l;
        card.push_back({l,0});
    }
    for(int i = 0; i < N; i++)
    {
        int r;
        cin >> r;
        card[i].right = r;
    }
    
    memset((int *)dp,-1,sizeof(dp));
    cout << DFS(0,0) << '\n';
    return 0;
}
