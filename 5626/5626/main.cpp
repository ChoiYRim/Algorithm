// Reference : https://mapocodingpark.blogspot.com/2020/03/BOJ-5626.html

#include <iostream>
#include <algorithm>

#define MAX 10001
#define MOD 1000000007

using namespace std;

int N;
int table[MAX] = {0,};

// 제단은 항상 직전 열과 비교해서 하나 작거나, 똑같거나 하나 크다
int dp[2][MAX] = {0,}; // [현재 열의 인덱스][(인덱스 == 높이)가 될 수 있는 경우의 수]

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> table[i];
        if(table[i] > min(i,(N-1)-i))
        {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    
    // 항상 첫 번째 열은 가능한 높이가 0이므로 경우의 수 1
    dp[0][0] = 1;
    dp[1][0] = 1;

    int cur,prev;
    for(int i = 0; i < N; i++)
    {
        cur = i % 2;
        prev = (cur+1) % 2;
        
        for(int j = 0; j < MAX/2; j++)
            dp[cur][j] = 0;
                
        if(table[i] != -1)
        {
            // 위에서 언급했다시피 직전 열보다 하나 작거나, 똑같거나 하나 더 크다
            for(int j = -1; j < 2; j++)
            {
                int temp = table[i]+j; // 직전 열의 높이 추정값
                if(temp < 0)
                    continue;
                
                dp[cur][table[i]] += dp[prev][temp];
                dp[cur][table[i]] %= MOD;
            }
        }
        else // -1이라면 경우의 수가 많아짐
        {
            for(int j = 0; j < MAX/2; j++)
            {
                if(j > min(i,(N-1)-i)) // 불가능한 경우의 수
                    break;
                
                for(int k = -1; k < 2; k++)
                {
                    int temp = j+k;
                    if(temp < 0)
                        continue;
                    
                    dp[cur][j] += dp[prev][temp];
                    dp[cur][j] %= MOD;
                }
            }
        }
        if(i == N-1)
            cout << dp[cur][0] % MOD << '\n';
    }
    
    return 0;
}
