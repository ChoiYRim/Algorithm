#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N,M;
int result = INT_MAX;
int start,last;
bool visit[1001] = {0,};
int W[1001][1001] = {0,};

void DFS(int cur,int weight)
{
    if(cur == last)
    {
        result = min(result,weight);
        return;
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(!visit[i] && W[cur][i]+weight < result)
        {
            visit[i] = true;
            DFS(i,weight+W[cur][i]);
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
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        W[a][b] = w;
    }
    cin >> start >> last;
    
    visit[start] = true;
    DFS(start,0);
    
    cout << result << '\n';
    return 0;
}
