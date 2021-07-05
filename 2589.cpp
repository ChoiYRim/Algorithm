#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define RANGE(x,y,H,W) ((0 <= x && x < W) && (0 <= y && y < H))

using namespace std;

struct _pos
{
    int y;
    int x;
};

int H,W;
int result = 0;
vector<vector<int>> v;
vector<vector<int>> dist;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    cin >> H >> W;
    for(int i = 0; i < H; i++)
    {
        string str = "";
        vector<int> temp;
        
        cin >> str;
        for(int j = 0; j < (int)str.length(); j++)
        {
            if(str[j] == 'L')
                temp.push_back(1);
            else
                temp.push_back(0);
        }
        v.push_back(temp);
    }
    
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(v[i][j]) // Land
            {
                dist = vector<vector<int>>(64,vector<int>(64,-1));

                // BFS
                queue<_pos> q;
                
                dist[i][j] = 0;
                q.push({i,j});
                while(!q.empty())
                {
                    _pos cur = q.front();
                    q.pop();
                    
                    int x = cur.x,y = cur.y;
                    
                    for(int k = 0; k < 4; k++)
                    {
                        int nx = x+dx[k],ny = y+dy[k];
                        
                        if(RANGE(nx,ny,H,W) && v[ny][nx] && dist[ny][nx] < 0)
                        {
                            dist[ny][nx] = dist[y][x]+1;
                            result = max(result,dist[ny][nx]);
                            q.push({ny,nx});
                        }
                    }
                }
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}
