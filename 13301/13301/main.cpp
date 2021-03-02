#include <iostream>
#include <algorithm>

using namespace std;

long long dp[128] = {0,};
long long len[128] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    
    len[1] = 1; len[2] = 1; len[3] = 2;
    dp[1] = 4; dp[2] = 6; dp[3] = 10;
    for(int i = 4; i <= 80; i++)
    {
        len[i] = len[i-1] + len[i-2];
        dp[i] = len[i] * 2 + (len[i]+len[i-1])*2;
    }
    
    cout << dp[N] << '\n';
    return 0;
}
