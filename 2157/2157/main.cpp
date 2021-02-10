#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N,M,K; // 도시의 개수 , 거쳐가는 도시의 수 , 개설된 항로의 수
int W[301][301] = {0,}; // i->j로 이동하는 항로의 기내식 점수
int dp[301][301] = {0,}; // dp[M][N] -> M번째, N번 도시를 방문했을 때 최대 값
int result = 0;

// 디버깅
void printArr(string str,int arr[301][301])
{
    cout << str << '\n';
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        W[a][b] = max(W[a][b],w);
    }
    
    // 초기화
    // 여행 경로는 반드시 1번 도시에서 시작해 N번 도시에서 끝난다.
    dp[1][1] = W[1][1]; // 1 번째, 자기 자신으로 돌아오는 항로
    for(int i = 1; i <= N; i++)
    {
        dp[2][i] = W[1][i]; // 2 번째, 1번에서 i번 도시를 방문할 때의 최대 값
        if(i == N)
            result = max(result,dp[2][i]);
    }
            
    // Step - 지나간 도시의 개수
    for(int step = 3; step <= M; step++)
    {
        for(int city = 1; city <= N; city++)
        {
            for(int prev = 1; prev < city; prev++)
            {
                if(dp[step-1][prev] && W[prev][city])
                {
                    dp[step][city] = max(dp[step][city],dp[step-1][prev]+W[prev][city]);
                    if(city == N)
                        result = max(result,dp[step][city]);
                }
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}
