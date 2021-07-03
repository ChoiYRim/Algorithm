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
    dp[1] = LOSE;
    dp[2] = VICTORY;
    dp[3] = LOSE;
    
    for(int i = 4; i <= N; i++)
    {
        if(min(dp[i-1],dp[i-3]) == 0)
            dp[i] = VICTORY;
        else
            dp[i] = LOSE;
    }
    if(dp[N] == LOSE)
        cout << "CY" << '\n';
    else
        cout << "SK" << '\n';
    return 0;
}
