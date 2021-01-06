#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _pos
{
    int y;
    int x;
    int m; // amount
}Pos;

int r,c,t; // row, column, time
int map[51][51];
int vy[4] = {-1,0,1,0};
int vx[4] = {0,1,0,-1};
Pos cleaner[2];

vector<Pos> dust;

void print_map(void)
{
    cout << "MAP" << '\n';
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            printf("%2d ", map[i][j]);
        }
        cout << '\n';
    }
}

void get_dust(void)
{
    dust.clear();
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(map[i][j] > 0)
                dust.push_back({i,j,map[i][j]});
        }
    }
}

void spread_dust(void) // step 1
{
    queue<Pos> q;
    
    get_dust();
    for(int i = 0; i < dust.size(); i++)
        q.push(dust[i]);
    
    while(!q.empty())
    {
        int cnt = 0;
        Pos p = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = p.y + vy[i];
            int nx = p.x + vx[i];
            
            if(0 < ny && ny <= r && 0 < nx && nx <= c)
            {
                if(map[ny][nx] != -1)
                {
                    cnt++;
                    map[ny][nx] += (p.m / 5);
                }
            }
        }
        if(cnt != 0)
        {
            map[p.y][p.x] -= ((p.m / 5) * cnt);
        }
    }
}

int up(Pos start,Pos end)
{
    int x = start.x;
    int ret = map[end.y][end.x];
    
    for(int i = end.y; i+1 <= start.y; i++)
        map[i][x] = map[i+1][x];
    map[start.y][x] = start.m;
    
    return ret;
}

int down(Pos start,Pos end)
{
    int x = start.x;
    int ret = map[end.y][end.x];
    
    for(int i = end.y; i-1 >= start.y; i--)
        map[i][x] = map[i-1][x];
    map[start.y][x] = start.m;
    
    return ret;
}

int left(Pos start,Pos end)
{
    int y = start.y;
    int ret = map[end.y][1];
    
    for(int i = 1; i+1 <= c; i++)
        map[y][i] = map[y][i+1];
    map[y][start.x] = start.m;
    
    return ret;
}

int right(Pos start,Pos end)
{
    int y = start.y;
    int ret = map[end.y][c];
    
    for(int i = c; i-1 > 1; i--)
        map[y][i] = map[y][i-1];
    map[y][2] = 0;
    
    return ret;
}

void circulate_air(void) // step 2
{
    int ret;
    
    // counter clockwise
    ret = right(cleaner[0],{cleaner[0].y,c,0});
    ret = up({cleaner[0].y-1,c,ret},{1,c,0});
    ret = left({1,c-1,ret},{1,1,0});
    ret = down({2,1,ret},{cleaner[0].y-1,1,0});
    
    // clockwise
    ret = right(cleaner[1],{cleaner[1].y,c,0});
    ret = down({cleaner[1].y+1,c,ret},{r,c,0});
    ret = left({r,c-1,ret},{r,1,0});
    ret = up({r-1,1,ret},{cleaner[1].y+1,1,0});

}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int time = 0,idx = 0;
    
    cin >> r >> c >> t;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1)
            {
                cleaner[idx++] = {i,j};
            }
        }
    }
    
    while(time < t)
    {
        spread_dust();
        //cout << "Spread ";
        //print_map();
        circulate_air();
        //cout << "Circulate ";
        //print_map();
        
        time++;
    }
    
    int result = 0;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            result += map[i][j];
        }
    }
    
    cout << result+2 << '\n';
    return 0;
}
