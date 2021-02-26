#include <cstring>
#include <iostream>
#include <algorithm>

#define MOD 1000000003

using namespace std;

int N,K;
int dp[1001][1001];

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset((int *)dp,0,sizeof(dp));
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = i;
    }
    for(int i = 2; i <= N; i++)
    {
        for(int j = 2; j <= N; j++)
        {
            dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%MOD;
        }
    }
    
    cout << (dp[N-3][K-1]+dp[N-1][K])%MOD << '\n';
    return 0;
}
