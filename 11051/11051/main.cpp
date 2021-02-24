#include <cstring>
#include <iostream>
#include <algorithm>

#define MOD 10007

using namespace std;

int N,K;
long long dp[1001][1001] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
        }
    }
    
    cout << dp[N][K] << '\n';
    return 0;
}
