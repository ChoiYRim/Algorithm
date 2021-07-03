#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#define RANGE(x,y,M,N) ((0 <= x && x < M) && (0 <= y && y < N))

using namespace std;

int TC,N,M,K;
vector<int> result;
vector<vector<int>> field;
vector<vector<bool>> visit;
int dy[4] = {-1,0,1,0}; // n e s w
int dx[4] = {0,1,0,-1};

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> TC;
    while(TC--)
    {
        int cnt = 0;
        vector<pair<int,int>> crop;
        field = vector<vector<int>>(55,vector<int>(55,0));
        visit = vector<vector<bool>>(55,vector<bool>(55,0));
        
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++)
        {
            int x,y;
            cin >> x >> y;
            field[y][x] = 1;
            crop.push_back({y,x});
        }
        
        for(int i = 0; i < (int)crop.size(); i++)
        {
            int x = crop[i].second,y = crop[i].first;
            if(visit[y][x])
                continue;
            else
            {
                cnt++;
                queue<pair<int,int>> q;
                q.push({y,x});
                visit[y][x] = true;
                while(!q.empty())
                {
                    int tx = q.front().second,ty = q.front().first;
                    q.pop();
                    
                    for(int j = 0; j < 4; j++)
                    {
                        int ny = ty+dy[j],nx = tx+dx[j];
                        
                        if(RANGE(nx,ny,M,N) && !visit[ny][nx] && field[ny][nx])
                        {
                            q.push({ny,nx});
                            visit[ny][nx] = true;
                        }
                    }
                }
            }
        }
        result.push_back(cnt);
    }
    
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
