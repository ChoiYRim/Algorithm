#include <vector>
#include <iostream>
#include <algorithm>

#define RANGE(x,y) ((0 <= x && x < M) && (0 <= y && y < N))

using namespace std;

int TC;
int N,M,K;
vector<int> result;
int dy[4] = {-1,0,1,0}; // n e s w
int dx[4] = {0,1,0,-1};
vector<vector<int>> field;
vector<vector<bool>> visit;

void DFS(int y,int x)
{
    visit[y][x] = true;
    
    for(int i = 0; i < 4; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if(RANGE(nx,ny) && field[ny][nx] && !visit[ny][nx])
            DFS(ny,nx);
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> TC;
    while(TC--)
    {
        int cnt = 0;
        field = vector<vector<int>>(55,vector<int>(55,0));
        visit = vector<vector<bool>>(55,vector<bool>(55,0));
        vector<pair<int,int>> crop;
        
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++)
        {
            int x,y;
            cin >> x >> y;
            crop.push_back({y,x});
            field[y][x] = 1;
        }
        
        for(int i = 0; i < (int)crop.size(); i++)
        {
            int y = crop[i].first;
            int x = crop[i].second;
            
            if(visit[y][x])
                continue;
            else
            {
                cnt++;
                DFS(y,x);
            }
        }
        result.push_back(cnt);
    }
    
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
