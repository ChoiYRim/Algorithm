#include <iostream>
#include <algorithm>

#define MAX 100001
#define INF 987654321

using namespace std;

int N;
int coin[2] = {2,5};
int dp[MAX];

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    fill(dp,dp+MAX,INF);
    dp[0] = 0;
    
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(i >= coin[j] && dp[i-coin[j]]+1 < dp[i])
            {
                dp[i] = dp[i-coin[j]]+1;
            }
        }
    }
    
    cout << (dp[N] != INF ? dp[N] : -1) << '\n';
    return 0;
}
