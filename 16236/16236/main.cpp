// Reference : https://yabmoons.tistory.com/160

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef struct _shark
{
    int y;
    int x;
    int size;
    int food;
    int time;
}Shark;

typedef struct _fish
{
    int y;
    int x;
    int dist;
}Fish;

int n;
int map[20][20];
bool visit[20][20];
Shark shark;
vector<Fish> fish;

int vy[] = {-1,0,1,0};
int vx[] = {0,1,0,-1};

bool sortFish(Fish& a,Fish& b)
{
    if(a.dist < b.dist)
        return true;
    else if(a.dist == b.dist)
    {
        if(a.y < b.y)
            return true;
        else if(a.y == b.y)
        {
            if(a.x < b.x)
                return true;
        }
    }
    
    return false;
}

void bfs(int y,int x)
{
    queue<pair<pair<int,int>,int>> q; // ((y좌표,x좌표),현재까지 움직인 거리)
    q.push({{y,x},0}); // 초기값으로 상어의 현재 좌표와 움직인 거리 0 입력
    visit[y][x] = true;
    
    while(!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int d = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + vy[i];
            int nx = x + vx[i];
            
            if(0 <= ny && ny < n && 0 <= nx && nx < n)
            {
                if(!visit[ny][nx]) // not visited
                {
                    if(map[ny][nx] == 0 || map[ny][nx] == shark.size)
                    {
                        visit[ny][nx] = true;
                        q.push({{ny,nx},d+1});
                    }
                    else if(map[ny][nx] < shark.size)
                    {
                        visit[ny][nx] = true;
                        
                        Fish temp;
                        temp.y = ny;
                        temp.x = nx;
                        temp.dist = d+1;
                        
                        fish.push_back(temp);
                        q.push({{ny,nx},d+1});

                    }
                }
            }
        }
    }
}

void reset_info(void)
{
    map[fish[0].y][fish[0].x] = 9;
    map[shark.y][shark.x] = 0;
    shark.y = fish[0].y;
    shark.x = fish[0].x;
    shark.food++;
    shark.time += fish[0].dist;
    if(shark.size == shark.food)
    {
        shark.size++;
        shark.food = 0;
    }
}

int main(int argc,const char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 9)
            {
                shark.y = i;
                shark.x = j;
                shark.size = 2;
                shark.food = 0;
                shark.time = 0;
            }
        }
    }
    
    while(1)
    {
        fish.clear();
        memset((bool *)visit,0,sizeof(visit));
        
        bfs(shark.y,shark.x); // 먹을 수 있는 물고기 벡터 생성
        
        if(!fish.size())
            break;
        else if(fish.size() == 1)
        {
            reset_info();
        }
        else if(fish.size() > 1)
        {
            sort(fish.begin(),fish.end(),sortFish);
            reset_info();
        }
    }
    
    cout << shark.time << '\n';
    return 0;
}
