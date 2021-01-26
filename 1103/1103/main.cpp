#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

#define RANGE(x,R) (1 <= x && x <= R)

using namespace std;

int N,M;
int Map[51][51]; // 지도 -> 0이 구멍
int dp[51][51]; // [][]
bool visit[51][51]; // 방문여부

int vy[4] = {-1,0,1,0}; // 북동남서
int vx[4] = {0,1,0,-1}; // 북동남서

int DFS(int y,int x)
{
    if(!RANGE(y,N) || !RANGE(x,M) || !Map[y][x])
        return 0;
    if(visit[y][x])
    {
        cout << -1 << endl;
        exit(0);
    }
    if(dp[y][x])
        return dp[y][x];
    
    visit[y][x] = true;
    for(int i = 0; i < 4; i++)
        dp[y][x] = max(dp[y][x],DFS(y+Map[y][x]*vy[i],x+Map[y][x]*vx[i])+1);
    visit[y][x] = false;
    return dp[y][x];
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        string str;
        
        cin >> str;
        for(int j = 1; j <= M; j++)
        {
            if(str[j-1] <= '9')
                Map[i][j] = str[j-1] - '0';
            if(str[j-1] == 'H')
                Map[i][j] = 0;
        }
    }
    memset((bool *)visit,0,sizeof(visit));
    memset((int *)dp,0,sizeof(dp));
    
    cout << DFS(1,1) << '\n';
    return 0;
}
