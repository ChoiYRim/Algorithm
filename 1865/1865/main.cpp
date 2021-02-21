#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;
};

int TC,N,M,W;

string BellmanFord(vector<Edge> edges,int V,int start)
{
    vector<int> distance(V+1,INF);
    distance[start] = 0;
    
    for(int i = 1; i <= V; i++)
    {
        for(auto& edge : edges)
        {
            if(distance[edge.start] == INF)
                continue;
            
            if(distance[edge.end] > distance[edge.start]+edge.weight)
            {
                if(i == V)
                {
                    return "YES";
                }
                distance[edge.end] = distance[edge.start]+edge.weight;
            }
        }
    }
    
    return "NO";
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    cin >> TC;
    while(TC--)
    {
        cin >> N >> M >> W;
        
        int S,E,T;
        vector<Edge> edges;
        
        for(int i = 0; i < M; i++)
        {
            cin >> S >> E >> T;
            edges.push_back({S,E,T});
            edges.push_back({E,S,T});
        }
        for(int i = 0; i < W; i++)
        {
            cin >> S >> E >> T;
            edges.push_back({S,E,-T});
        }
                
        vector<int> distance(N+1,INF);
        bool check = false;
        distance[1] = 0;
        
        
        //for(int i = 1; i <= N; i++) // 시작점 1~N
        //{
            for(int j = 1; j <= N; j++)
            {
                for(auto& edge : edges)
                {
                    if(distance[edge.end] > distance[edge.start]+edge.weight)
                    {
                        distance[edge.end] = distance[edge.start]+edge.weight;
                    }
                }
            }
        
            for(auto& edge : edges)
            {
                if(distance[edge.end] > distance[edge.start]+edge.weight)
                {
                    check = true;
                    break;
                }
            }
        //}
        
        if(check)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
    return 0;
}
