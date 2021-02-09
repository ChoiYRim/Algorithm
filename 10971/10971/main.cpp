#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int W[11][11] = {0,};
bool visit[11] = {0,};
int result = INT_MAX;

// 현재 방문하는 점이 몇 번째? , 현재 점은 ? , 가중치
void DFS(int depth,int cur,int weight)
{
    if(depth == N && W[cur][1])
    {
        result = min(result,weight+W[cur][1]);
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(!visit[i] && W[cur][i] && weight+W[cur][i] < result)
        {
            visit[i] = true;
            DFS(depth+1,i,weight+W[cur][i]);
            visit[i] = false;
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++) // (1,1) ~ (N,N) 까지
        for(int j = 1; j <= N ; j++)
            cin >> W[i][j];
    
    visit[1] = true;
    DFS(1,1,0);
    
    cout << result << '\n';
    return 0;
}
