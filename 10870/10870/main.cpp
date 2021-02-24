#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[21] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for(int i = 3; i <= N; i++)
        dp[i] = dp[i-1] + dp[i-2];
    
    cout << dp[N] << '\n';
    return 0;
}
