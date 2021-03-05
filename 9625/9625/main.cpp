#include <iostream>
#include <algorithm>

using namespace std;

int K;
int dp[46][2] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> K;
    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 0; dp[1][1] = 1;
    
    for(int i = 2; i <= K; i++)
    {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
    }
    
    cout << dp[K][0] << " " << dp[K][1] << '\n';
    return 0;
}
