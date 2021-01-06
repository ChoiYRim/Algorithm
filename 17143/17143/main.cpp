#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct _shark
{
    int s; // velocity
    int d; // direction
    int z; // size
    bool moved;
}Shark;

int result,r,c,m;
int vy[] = {0,-1,1,0,0};
int vx[] = {0,0,0,1,-1};
vector<Shark> shark[111][111];

void print_shark(void)
{
    cout << "Shark " << endl;
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(shark[i][j].size() > 0)
                cout << shark[i][j][0].z << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

bool sortShark(Shark& a,Shark& b)
{
    if(a.z > b.z)
        return true;
    return false;
}

void shark_move(void)
{
    bool moved;
    int ny,nx,s,d,z;
    
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(shark[i][j].size() > 0)
            {
                if(!shark[i][j][0].moved)
                {
                    shark[i][j][0].moved = true;
                    
                    s = shark[i][j][0].s;
                    d = shark[i][j][0].d;
                    z = shark[i][j][0].z;
                    moved = shark[i][j][0].moved;
                    
                    if(d < 3)
                    {
                        ny = i;
                        nx = j;
                        for(int k = 1; k <= s; k++)
                        {
                            ny += vy[d];
                            if(ny == 0)
                            {
                                if(d == 1)
                                    d = 2;
                                else
                                    d = 1;
                                ny = 2;
                            }
                            else if(ny == r+1)
                            {
                                if(d == 1)
                                    d = 2;
                                else
                                    d = 1;
                                ny = r-1;
                            }
                        }
                    }
                    else
                    {
                        ny = i;
                        nx = j;
                        for(int k = 1; k <= s; k++)
                        {
                            nx += vx[d];
                            if(nx == 0)
                            {
                                if(d == 3)
                                    d = 4;
                                else
                                    d = 3;
                                nx = 2;
                            }
                            else if(nx == c+1)
                            {
                                if(d == 3)
                                    d = 4;
                                else
                                    d = 3;
                                nx = c-1;
                            }
                        }
                    }
                    shark[ny][nx].push_back({s,d,z,moved});
                    shark[i][j].erase(shark[i][j].begin());
                }
            }
        }
    }
    
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(shark[i][j].size() > 1)
            {
                sort(shark[i][j].begin(),shark[i][j].end(),sortShark);
                Shark temp = shark[i][j][0];
                shark[i][j].clear();
                shark[i][j].push_back(temp);
            }
        }
    }
    
    for(int i = 1; i <= r; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(shark[i][j].size() > 0 && shark[i][j][0].moved)
            {
                shark[i][j][0].moved = false;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int p = 0;
    
    result = 0;
    
    cin >> r >> c >> m;
    for(int i = 0; i < m; i++)
    {
        int ty,tx,ts,td,tz;
        
        cin >> ty >> tx >> ts >> td >> tz;
        shark[ty][tx].push_back({ts,td,tz,false});
    }
    
    while(p <= c)
    {
        ++p;
        if(p > c)
            break;
        
        for(int i = 1; i <= r; i++)
        {
            if(shark[i][p].size() == 1)
            {
                result += shark[i][p][0].z;
                shark[i][p].clear();
                break;
            }
        }
        
        shark_move();
    }
    
    cout << result << '\n';
    return 0;
}
