#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int R,C;
vector<vector<int>> lake;
pair<int,int> b1,b2; // {y,x}
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue<pair<int,int>> water;

inline bool isRange(int x,int y) { return ((0 <= x && x < C) && (0 <= y && y < R)); }

void iceMelting(void)
{
    int size = (int)water.size();
    
    while(size--)
    {
        pair<int,int> p = water.front();
        water.pop();
        int y = p.first,x = p.second;
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y+dy[i],nx = x+dx[i];
            
            if(!isRange(nx,ny))
                continue;
            if(lake[ny][nx] == 1)
            {
                lake[ny][nx] = 0;
                water.push({ny,nx});
            }
        }
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int day = 0;
    b1 = b2 = {-1,-1};
    
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        string str = "";
        vector<int> temp;
        cin >> str;
        for(int j = 0; j < C; j++)
        {
            if(str[j] == '.')
            {
                temp.push_back(0);
                water.push({i,j});
            }
            else if(str[j] == 'X')
                temp.push_back(1);
            else
            {
                temp.push_back(2);
                water.push({i,j});
                if(b1.first != -1)
                    b2 = {i,j};
                else
                    b1 = {i,j};
            }
        }
        lake.push_back(temp);
    }
    
    queue<pair<int,int>> q;
    vector<vector<bool>> visit;
    
    visit = vector<vector<bool>>(R,vector<bool>(C,false));
    q.push({b1.first,b1.second});
    visit[0][0] = true;
    
    while(1)
    {
        queue<pair<int,int>> sq;
        bool check = false;
        
        while(!q.empty())
        {
            pair<int,int> cur = q.front();
            q.pop();
            
            int y = cur.first,x = cur.second;
            if(b2.first == y && b2.second == x)
            {
                check = true;
                break;
            }
            for(int i = 0; i < 4; i++)
            {
                int ny = y+dy[i],nx = x+dx[i];
                
                if(!isRange(nx,ny) || visit[ny][nx])
                    continue;
                visit[ny][nx] = true;
                if(lake[ny][nx] == 1)
                {
                    sq.push({ny,nx});
                    continue;
                }
                q.push({ny,nx});
            }
        }
        
        if(check)
            break;
        
        q = sq;
        iceMelting();
        day++;
    }
    
    cout << day << '\n';
    return 0;
}
