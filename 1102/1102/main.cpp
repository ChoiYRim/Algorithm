#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX 987654321

using namespace std;

int N,P;
int W[16][16] = {0,};
int dp[1 << 16]; // i번 발전소를 가동시키기 위한 최소 비용

int bitCount(int bits)
{
    int num = 0;
    
    while(bits != 0)
    {
        if(bits & 1)
            num++;
        bits = bits >> 1;
    }
    
    return num;
}

int DFS(int cur)
{
    if(bitCount(cur) >= P)
        return 0;
    if(dp[cur] != -1)
        return dp[cur];
    
    dp[cur] = MAX;
    for(int i = 0; i < N; i++) // i번 발전소 기준으로 체크할 예정
    {
        if((cur & (1 << i)) == 0) // i번 발전소가 안켜져있네?
            continue; // pass
        for(int j = 0; j < N; j++)
        {
            if((cur & (1 << j)) == 0) // 다음 작동시키려는 발전기가 꺼져있으면
            {
                int next = (cur | (1 << j));
                dp[cur] = min(dp[cur],W[i][j]+DFS(next));
            }
        }
    }
    
    return dp[cur];
}

int makeBits(string gen)
{
    int bits = 0;
    
    for(int i = 0; i < gen.length(); i++)
    {
        if(gen[i] == 'Y')
            bits |= (1 << i);
    }
    
    return bits;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    string gen = "";
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> W[i][j];
        
    cin >> gen;
    cin >> P;
    
    int bits = makeBits(gen);
    memset((int *)dp,-1,sizeof(dp));
    int result = DFS(bits);
    
    result == MAX ? cout << -1 << '\n' : cout << result << '\n';
    return 0;
}
