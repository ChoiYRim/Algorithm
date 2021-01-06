/*
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,d;
vector<vector<int> > map;

int vect_y[4] = {-1,0,1,0}; // north , east , south , west
int vect_x[4] = {0,1,0,-1}; // same with above

void print_map(void)
{
    char temp;
    
    cout << "Map Printing" << '\n';
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 3)
                temp = 'O';
            else if(map[i][j] == 2)
                temp = 'X';
            else
                temp = '1';
            cout << temp << " ";
        }
        
        cout << '\n';
    }
}

int change_direction(int cur_d)
{
    int next_d;
    
    if(cur_d == 0)
        cur_d = 4;
    
    next_d = cur_d-1;
    
    return next_d;
}

int main(int argc,const char * argv[])
{
    bool check = false;
    int result = 0,x,y;
    int next_x,next_y;
    pair<int,int> robot;
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> y >> x >> d;
    
    robot = {y,x}; // height, width
    
    for(int i = 0; i < n; i++)
    {
        vector<int> row;
        for(int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            
            row.push_back(temp);
        }
        map.push_back(row);
    }
    
    print_map();
    
    while(1)
    {
        if(map[robot.first][robot.second] == 0) // 1
        {
            result++;
            map[robot.first][robot.second] = 2;
            print_map();
        }
        
        check = false;
        for(int i = 0; i < 4; i++)
        {
            d = change_direction(d);
            next_y = robot.first + vect_y[d];
            next_x = robot.second + vect_x[d];
            
            if(map[next_y][next_x] == 0) // 2-1
            {
                check = true;
                robot = {next_y,next_x};
                break;
            }
        }
        if(check)
            continue;
        
        int temp_d = change_direction(d);
        next_y = robot.first + vect_y[temp_d];
        next_x = robot.second + vect_x[temp_d];
        
        if(map[next_y][next_x] != 0)
        {
            if(d > 1) // reverse direction
                d -= 2;
            else
                d += 2;
            
            next_y = robot.first + vect_y[d];
            next_x = robot.second + vect_x[d];
            
            if(map[next_y][next_x] == 1)
            {
                break;
            }
            
            robot = {next_y,next_x};
        }
    }
    cout << result << '\n';
    return 0;
}
*/

#include<iostream>
 
#define endl "\n"
#define MAX 50
using namespace std;
 
int N, M;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
pair<pair<int, int>, int> Robot;
 
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
 
void Input()
{
    cin >> N >> M;
    cin >> Robot.first.first >> Robot.first.second >> Robot.second;
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
int Turn_Direction(int d)
{
    if (d == 0)
        return 3;
    else if (d == 1)
        return 0;
    else if (d == 2)
        return 1;
    else if (d == 3)
        return 2;
    return -1;
}
 
void Solution()
{
    int x = Robot.first.first;
    int y = Robot.first.second;
    int d = Robot.second;
    int Room = 0;
    MAP[x][y] = 2;
    Room++;
 
    int nx, ny, nd;
 
    while (1)
    {
        int Tmp_d = d;
        bool Can_Clean = false;
        int CanNotClean = 0;
        for (int i = 0; i < 4; i++)        // 왼쪽방향으로부터 4방향 차례대로 탐색
        {
            nd = Turn_Direction(d);
            nx = x + dx[nd];
            ny = y + dy[nd];
            
            if (MAP[nx][ny] == 0)
            {
                Can_Clean = true;
                break;
            }
            else if (MAP[nx][ny] == 1 || MAP[nx][ny] == 2 || (nx < 0 || ny <0 || nx >=N || ny >=M))
            {
                d = nd;
                CanNotClean++;
            }
        }
 
        if (Can_Clean == true)
        {
            MAP[nx][ny] = 2;
            Room++;
            d = nd;
        }
 
        if (CanNotClean == 4)
        {
            nx = x - dx[Tmp_d];
            ny = y - dy[Tmp_d];
            d = Tmp_d;
            if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || MAP[nx][ny] == 1 )
            {
                break;
            }
        }
        x = nx;
        y = ny;
    }
    cout << Room << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
