#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define RANGE(x,N) (0 <= x && x < N)

using namespace std;

struct Pos
{
    int y;
    int x;
    int step;
};

int TC;
int dy[8] = {-1,-2,-2,-1,1,2,2,1};
int dx[8] = {-2,-1,1,2,2,1,-1,-2};

vector<Pos> start,last;
vector<int> N,result;

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> TC;
    while(TC--)
    {
        int Size;
        cin >> Size;
        N.push_back(Size);
        
        int y,x; // row , column
        
        cin >> y >> x;
        start.push_back({y,x,0});
        cin >> y >> x;
        last.push_back({y,x,0});
    }
    
    for(int i = 0; i < N.size(); i++)
    {
        int Size = N[i];
        queue<Pos> bfs_q;
        bfs_q.push(start[i]);
        bool visit[301][301];
        
        memset((bool *)visit,false,sizeof(visit));
        visit[start[i].y][start[i].x] = true;
        while(!bfs_q.empty())
        {
            Pos cur = bfs_q.front();
            bfs_q.pop();
            
            if(cur.y == last[i].y && cur.x == last[i].x)
            {
                result.push_back(cur.step);
                break;
            }
            
            for(int j = 0; j < 8; j++)
            {
                int ny = cur.y + dy[j];
                int nx = cur.x + dx[j];
                
                if(RANGE(ny,Size) && RANGE(nx,Size) && !visit[ny][nx])
                {
                    visit[ny][nx] = true;
                    bfs_q.push({ny,nx,cur.step+1});
                }
            }
        }
    }
    
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
