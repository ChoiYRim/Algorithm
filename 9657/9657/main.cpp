#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1024] = {0,};

enum RESULT
{
    LOSE = 0,VICTORY
};

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    dp[1] = VICTORY;
    dp[2] = LOSE;
    dp[3] = VICTORY;
    dp[4] = VICTORY;
    
    for(int i = 5; i <= N; i++)
    {
        if(min(dp[i-1],min(dp[i-3],dp[i-4])) == VICTORY)
            dp[i] = LOSE;
        else
            dp[i] = VICTORY;
    }
    if(dp[N] == LOSE)
        cout << "CY" << '\n';
    else
        cout << "SK" << '\n';
    return 0;
}
