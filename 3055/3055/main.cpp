#include <queue>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>

#define RANGE(x,L) (0 <= x && x < L)

using namespace std;

struct Pos
{
    int y; // row
    int x; // column
    int time;
};

/*
 1. 비어있음 : 0 ('.')
 
 2. 물 있음 : 1 ('*')
 
 3. 돌 덩이 : 2 ('X')
 
 4. 고슴도치 : 3 ('S')
 
 5. 비버 굴 : 4 ('D')
*/

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int R,C,waterTime = 1; // Row , Column
    vector<vector<int>> woods; // map
    vector<Pos> water; // 홍수 현황
    Pos start,dest; // start : 고슴도치 시작 위치 , dest : 비버굴
    
    int vy[4] = {-1,0,1,0}; // 북 동 남 서
    int vx[4] = {0,1,0,-1}; // "
    queue<Pos> q;
    bool visit[51][51];
    
    memset((bool *)visit,0,sizeof(visit));
    
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        vector<int> v;
        
        string temp = "";
        cin >> temp;
        for(int j = 0; j < C; j++)
        {
            int check;
            
            if(temp[j] == '.') // 비어있음
                check = 0;
            else if(temp[j] == '*') // 물
            {
                check = 1;
                water.push_back({i,j,0});
            }
            else if(temp[j] == 'X') // 돌
                check = 2;
            else if(temp[j] == 'S') // 고슴도치 위치
            {
                check = 3;
                start = {i,j,0};
                visit[i][j] = true;
            }
            else if(temp[j] == 'D') // 도착지
            {
                check = 4;
                dest = {i,j,0};
            }
            
            v.push_back(check);
        }
        woods.push_back(v);
    }
    
    q.push(start);
    while(!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        
        if(cur.y == dest.y && cur.x == dest.x)
        {
            cout << cur.time << '\n';
            return 0;
        }
        
        int ny,nx,time;
        vector<Pos> tempW;
        
        if(waterTime == cur.time+1)
        {
            for(int i = 0; i < (int)water.size(); i++) // 미리 물 확산시키기
            {
                for(int j = 0; j < 4; j++)
                {
                    ny = water[i].y+vy[j];
                    nx = water[i].x+vx[j];
                    time = water[i].time+1;
                    
                    if(RANGE(ny,R) && RANGE(nx,C) && woods[ny][nx] == 0)
                    {
                        woods[ny][nx] = 1;
                        tempW.push_back({ny,nx,time});
                    }
                }
            }
            for(int i = 0; i < (int)tempW.size(); i++)
                water.push_back(tempW[i]);
            waterTime++;
        }
        
        time = cur.time+1;
        
        for(int i = 0; i < 4; i++)
        {
            ny = cur.y+vy[i];
            nx = cur.x+vx[i];
            
            if(RANGE(ny,R) && RANGE(nx,C) && !visit[ny][nx])
            {
                if(woods[ny][nx] == 4)
                {
                    cout << time << '\n';
                    return 0;
                }
                else if(woods[ny][nx] == 0)
                {
                    visit[ny][nx] = true;
                    q.push({ny,nx,time});
                }
            }
        }
        
    }
    
    cout << "KAKTUS" << '\n';
    return 0;
}
