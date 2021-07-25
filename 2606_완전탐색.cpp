#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N,M;
int result = 0;
bool network[101][101];
bool visit[101] = {0,};
queue<int> q;

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset((bool *)network,0,sizeof(network));
    
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int u,v;
        cin >> u >> v;
        network[u][v] = true;
        network[v][u] = true;
    }
    
    visit[1] = true;
    q.push(1);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for(int i = 1; i <= 100; i++)
        {
            if(!visit[i] && network[cur][i])
            {
                q.push(i);
                visit[i] = true;
                result++;
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}
