#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int seat[64];
int dp[44] = {0,};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 1; i <= 40; i++)
        seat[i] = i;
    
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int s;
        cin >> s;
        seat[s] = 0;
    }
    if(N == M)
    {
        cout << 1 << '\n';
        return 0;
    }
    
    dp[0] = 1;
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= N; i++)
        dp[i] = dp[i-2] + dp[i-1];
    if(M == 0)
    {
        cout << dp[N] << '\n';
        return 0;
    }
    
    int i = 1,row = 0,result = 1;
    while(i <= N)
    {
        if(seat[i] != 0)
            row++;
        else
        {
            result *= dp[row];
            row = 0;
        }
        i++;
    }
    if(row > 0)
        result *= dp[row];
    
    cout << result << '\n';
    return 0;
}
