#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n,m; // height, width
int map[11][11];
int result = INT_MAX;

vector<pair<int,int> > pos;
vector<vector<pair<int,int> > > cctv[11]; // CCTV[1~5][dir]

void print_map(int p[11][11])
{
    cout << "MAP" << endl;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cout << p[i][j] << ' ';
        }
        cout << '\n';
    }
}

void set_cctv(void)
{
    vector<pair<int,int> > temp;
    
    temp.push_back({0,1}); // East
    cctv[1].push_back(temp);
    temp.clear();
    
    temp.push_back({1,0}); // South
    cctv[1].push_back(temp);
    temp.clear();
    
    temp.push_back({0,-1}); // West
    cctv[1].push_back(temp);
    temp.clear();
    
    temp.push_back({-1,0}); // North
    cctv[1].push_back(temp);
    temp.clear();
        
    temp.push_back({0,1});
    temp.push_back({0,-1});
    cctv[2].push_back(temp);
    temp.clear();
    
    temp.push_back({-1,0});
    temp.push_back({1,0});
    cctv[2].push_back(temp);
    temp.clear();
    
    temp.push_back({-1,0});
    temp.push_back({0,1});
    cctv[3].push_back(temp);
    temp.clear();
    
    temp.push_back({0,1});
    temp.push_back({1,0});
    cctv[3].push_back(temp);
    temp.clear();
    
    temp.push_back({1,0});
    temp.push_back({0,-1});
    cctv[3].push_back(temp);
    temp.clear();
    
    temp.push_back({0,-1});
    temp.push_back({-1,0});
    cctv[3].push_back(temp);
    temp.clear();
    
    temp.push_back({0,-1});
    temp.push_back({-1,0});
    temp.push_back({0,1});
    cctv[4].push_back(temp);
    temp.clear();
    
    temp.push_back({-1,0});
    temp.push_back({0,1});
    temp.push_back({1,0});
    cctv[4].push_back(temp);
    temp.clear();
    
    temp.push_back({0,1});
    temp.push_back({1,0});
    temp.push_back({0,-1});
    cctv[4].push_back(temp);
    temp.clear();
    
    temp.push_back({-1,0});
    temp.push_back({0,-1});
    temp.push_back({1,0});
    cctv[4].push_back(temp);
    temp.clear();

    temp.push_back({-1,0});
    temp.push_back({0,1});
    temp.push_back({1,0});
    temp.push_back({0,-1});
    cctv[5].push_back(temp);
    temp.clear();
}

int blind_spot(int p[11][11])
{
    int sum = 0;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(p[i][j] == 0)
            {
                sum++;
            }
        }
    }
    
    result = min(result,sum);
    return sum;
}

void reset_map(int origin[11][11],int save[11][11])
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            save[i][j] = origin[i][j];
        }
    }
}

// 현재 map , 현재 감시 방향 , 다음 CCTV index
void dfs(int page[11][11],vector<pair<int,int>> cur,int depth)
{
    // map 바꾸기
    int dy,dx; // y축 방향 , x축 방향
    int new_page[11][11];
    
    for(int i = 0; i < cur.size(); i++)
    {
        dy = cur[i].first; dx = cur[i].second;
        if(dy > 0)
        {
            for(int j = pos[depth].first+1; j <= n; j++)
            {
                if(page[j][pos[depth].second] == 0)
                {
                    page[j][pos[depth].second] = 7;
                }
                else if(page[j][pos[depth].second] == 6)
                    break;
            }
        }
        else if(dy < 0)
        {
            for(int j = pos[depth].first-1; j > 0; j--)
            {
                if(page[j][pos[depth].second] == 0)
                {
                    page[j][pos[depth].second] = 7;
                }
                else if(page[j][pos[depth].second] == 6)
                    break;
            }
        }
        if(dx > 0)
        {
            for(int j = pos[depth].second+1; j <= m; j++)
            {
                if(page[pos[depth].first][j] == 0)
                {
                    page[pos[depth].first][j] = 7;
                }
                else if(page[pos[depth].first][j] == 6)
                    break;
            }
        }
        else if(dx < 0)
        {
            for(int j = pos[depth].second-1; j > 0; j--)
            {
                if(page[pos[depth].first][j] == 0)
                {
                    page[pos[depth].first][j] = 7;
                }
                else if(page[pos[depth].first][j] == 6)
                    break;
            }
        }
    }
    
    // 다음 CCTV 호출
    if(depth+1 >= pos.size())
    {
        //print_map(page);
        blind_spot(page);
        return;
    }
    
    int new_cur = page[pos[depth+1].first][pos[depth+1].second];
    
    reset_map(page,new_page);
    for(int i = 0; i < cctv[new_cur].size(); i++)
    {
        dfs(new_page,cctv[new_cur][i],depth+1);
        reset_map(page,new_page);
    }
}

int main(int argc, const char * argv[])
{
    int save[11][11];
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if(map[i][j] != 0 && map[i][j] != 6)
                pos.push_back({i,j});
        }
    }
    
    if(pos.size() == 0)
    {
        blind_spot(map);
        cout << result << '\n';
        return 0;
    }
    
    int cur = map[pos[0].first][pos[0].second];
    
    set_cctv();
    reset_map(map,save);
    for(int i = 0; i < cctv[cur].size(); i++)
    {
        dfs(save,cctv[cur][i],0);
        reset_map(map,save);
    }
        
    cout << result << '\n';
    return 0;
}
