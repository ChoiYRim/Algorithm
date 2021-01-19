#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

#define ISRANGE(x,r) (0 < x && x <= r)
#define ISIT(A,B) (A.x == B.x && A.y == B.y)

using namespace std;

int N,M;

struct Pos
{
    int x;
    int y;
    int fuel; // 연료
    int dist; // 이동 거리
};

struct Passenger
{
    Pos start;
    Pos end;
};

int vy[4] = {-1,0,1,0}; // 북 동 남 서
int vx[4] = {0,1,0,-1}; // 북 동 남 서

Pos taxi;
int map[32][32]; // 지도
vector<Passenger> pass; // 승객
bool visit[32][32];

bool comp(const Passenger &p1,const Passenger &p2)
{
    if(p1.start.y == p2.start.y)
    {
        return p1.start.x <= p2.start.x;
    }
    return p1.start.y < p2.start.y;
}

Pos getQueue(Pos start,Pos end)
{
    queue<Pos> q;
    Pos ret = {-1,-1,-1,-1};
    
    memset((bool *)visit,0,sizeof(visit));
    visit[start.y][start.x] = true;
    
    q.push(start);
    while(!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        
        if(cur.fuel < 0)
            continue;
        
        if(ISIT(cur,end))
            return cur;
        
        //cout << "Cur : [" << cur.x << "," << cur.y << "]\n";
        
        for(int j = 0; j < 4; j++)
        {
            int ny = vy[j]+cur.y;
            int nx = vx[j]+cur.x;
            
            if(ISRANGE(ny,N) && ISRANGE(nx,N) && !map[ny][nx] && !visit[ny][nx])
            {
                visit[ny][nx] = true;
                q.push({nx,ny,cur.fuel-1,cur.dist+1});
            }
        }
    }
    
    return ret;
}

pair<int,int> getPassenger(Pos pos)
{
    pair<int,int> ret = {-1,0xfffffff}; // [승객 인덱스] [이동한 거리]
    int len = (int)pass.size();
    
    for(int i = 0 ; i < len; i++)
    {
        Pos target = pass[i].start;
        Pos result = getQueue(pos,target);
        
        if(result.x == -1 && result.y == -1)
            continue;
        if(ret.second > result.dist)
        {
            ret.second = result.dist;
            ret.first = i;
        }
    }
    
    return ret;
}

int solution(void)
{
    pair<int,int> next;
    int len,idx,dist;
    
    len = (int)pass.size();
    for(int i = 0; i < len; i++)
    {
        queue<Pos> q;
        Pos target,result;
        
        sort(pass.begin(),pass.end(),comp);
        
        next = getPassenger(taxi);
        if(next.first == -1)
            return -1;
        
        idx = next.first;
        dist = next.second;
        
        taxi = {pass[idx].start.x,pass[idx].start.y,taxi.fuel-dist,0};
        target = pass[idx].end;
        pass.erase(pass.begin()+idx);
        
        result = getQueue(taxi,target);
        if(result.y == -1 && result.x == -1)
            return -1;
        taxi = result;
        taxi.dist = 0;
        taxi.fuel += result.dist * 2;
    }
    
    return taxi.fuel;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    taxi = {-1,-1,0,0};
    cin >> N >> M >> taxi.fuel;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int temp;
            cin >> temp;
            map[i][j] = temp;
        }
    }
    cin >> taxi.y >> taxi.x;
    for(int i = 0; i < M; i++)
    {
        Passenger p = {-1,-1,0,0};
        cin >> p.start.y >> p.start.x >> p.end.y >> p.end.x;
        pass.push_back(p);
    }
    
    taxi.dist = 0;
    cout << solution() << '\n';
    return 0;
}
