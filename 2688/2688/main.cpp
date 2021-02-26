#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int TC,N;
long long dp[65][10];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset((long long *)dp,0,sizeof(dp));
    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= 64; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            long long sum = 0;
            for(int k = j; k < 10; k++)
                sum += dp[i-1][k];
            dp[i][j] = sum;
        }
    }
    
    cin >> TC;
    while(TC--)
    {
        long long result = 0;
        
        cin >> N;
        for(int i = 0; i < 10; i++)
            result += dp[N][i];
        cout << result << '\n';
    }
    
    return 0;
}
