#include <vector>
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int C,N;
int Set[21][2] = {0,};
int dp[1024] = {0,}; // dp[i] = i명의 고객을 확보하기 위해 드는 최소의 값

int DFS(int c)
{
    if(c <= 0)
        return 0;
    if(dp[c] != INF)
        return dp[c];
    
    for(int i = 0; i < N; i++)
    {
        int cost = DFS(c-Set[i][1])+Set[i][0];
        dp[c] = min(dp[c],cost);
    }
    
    return dp[c];
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
            
    fill(dp,dp+1024,INF);
    
    cin >> C >> N;
    for(int i = 0; i < N; i++)
        cin >> Set[i][0] >> Set[i][1];
    
    cout << DFS(C) << '\n';
    return 0;
}
