#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n,l,r;
int result = 0;
vector<vector<int>> c;
bool visit[52][52];

int vect_y[4] = {0,0,1,-1};
int vect_x[4] = {1,-1,0,0};

int abs(int a)
{
    if(a < 0)
        return -a;
    return a;
}

void print_map(char * str)
{
    cout << str << '\n';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
}

bool make_union(void)
{
    queue<pair<int,int>> q;
    vector<vector<pair<int,int>>> set;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visit[i][j])
            {
                vector<pair<int,int>> temp;
                q.push({i,j});
                visit[i][j] = true;
                temp.push_back({i,j});
                
                while(!q.empty())
                {
                    int y,x,ny,nx;
                    pair<int,int> p = q.front();
                    q.pop();
                    
                    y = p.first;
                    x = p.second;
                    
                    for(int k = 0; k < 4; k++)
                    {
                        ny = y+vect_y[k];
                        nx = x+vect_x[k];
                        
                        if(0 <= ny && ny < n && 0 <= nx && nx < n && !visit[ny][nx])
                        {
                            if(l <= abs(c[y][x]-c[ny][nx]) && abs(c[y][x]-c[ny][nx]) <= r)
                            {
                                temp.push_back({ny,nx});
                                visit[ny][nx] = true;
                                q.push({ny,nx});
                            }
                        }
                    }
                    
                    if((int)q.size() == 0) // 더 이상 늘릴 수 있는 공간이 없다면
                    {
                        if((int)temp.size() == 1)
                            continue;
                        set.push_back(temp);
                    }
                }
            }
        }
    }
    
    if((int)set.size() > 0)
    {
        for(int i = 0; i < set.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < set[i].size(); j++)
            {
                sum += c[set[i][j].first][set[i][j].second];
            }
            for(int j = 0; j < set[i].size(); j++)
            {
                c[set[i][j].first][set[i][j].second] = sum / set[i].size();
            }
        }
        
        result++;
    }
    else
        return false;
    return true;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
    {
        vector<int> temp;
        for(int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            temp.push_back(a);
        }
        c.push_back(temp);
    }
    
    while(make_union())
    {
        //print_map("[STEP]");
        memset((bool *)visit,0,sizeof(visit));
    }
    
    cout << result << '\n';
    return 0;
}
