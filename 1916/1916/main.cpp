#include <vector>
#include <iostream>
#include <algorithm>

#define MAX 987654321

using namespace std;

int N,M;
int start,last;
vector<int> cost;
vector<vector<int>> W;
vector<bool> visit;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    W = vector<vector<int>>((N+10),vector<int>(N+10,MAX));
    cost = vector<int>(N+10,MAX);
    visit = vector<bool>(N+10,false);
    
    for(int i = 0; i < M; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        W[a][b] = min(W[a][b],w);
    }
    cin >> start >> last;
    
    for(int i = 1; i <= N; i++)
        cost[i] = W[start][i];
    
    int vnear = start; // 가장 가까운 정점
    visit[start] = true;
    
    for(int loop = 0; loop < N; loop++)
    {
        int dist = MAX;
        for(int i = 1; i <= N; i++)
        {
            if(!visit[i] && cost[i] < dist)
            {
                vnear = i; // 가장 가까운 정점 교체
                dist = cost[i];
            }
        }
        
        // 가장 가까운 정점의 시점에서 비용 계산
        for(int i = 1; i <= N; i++)
        {
            // 이미 방문했거나 vnear에서 방문할 방법이 없다면 continue
            if(visit[i] || W[vnear][i] == MAX)
                continue;
            
            cost[i] = min(cost[i],cost[vnear]+W[vnear][i]);
        }
        visit[vnear] = true;
    }
    
    cout << cost[last] << '\n';
    return 0;
}
