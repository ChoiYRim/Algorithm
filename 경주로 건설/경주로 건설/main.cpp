#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct _pos
{
    int y; // row
    int x; // column
}Pos;

typedef struct _cur
{
    int y;
    int x;
    int dir;
    int output;
}Cur;

/*
void print_visit(int n,int output)
{
    cout << "Visit Array" << endl;
    cout << "Output : " << output << endl;
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << (visit[i][j] == true ? 1 : 0) << " ";
        }
        cout << endl;
    }
}

// 회전 횟수 , 결과값 , 경주로 부지 변의 길의 , 현재 위치 , 부지 map
void dfs(int dir,int output,int n,Pos pos,vector<vector<int>> board)
{
    int ny,nx;
    
    if(pos.y == n-1 && pos.x == n-1)
    {
        if(result > output)
            result = output;
        return;
    }
    
    visit[pos.y][pos.x] = true;
        
    for(int i = 0; i < 4; i++)
    {
        ny = vy[i] + pos.y;
        nx = vx[i] + pos.x;
        
        if(0 <= ny && ny < n && 0 <= nx && nx < n && !board[ny][nx] && !visit[ny][nx])
        {
            int ndir;
            int temp = 100;
            
            if(dir == -1)
                ndir = (i % 2 == 1 ? 0 : 1); // 0 : 동 서 , 1 : 남 북
            else
            {
                if(dir == 0) // 동 서
                {
                    if(!(i % 2)) // 남 북
                    {
                        temp += 500;
                        ndir = 1;
                    }
                    else
                        ndir = 0;
                }
                else // 남 북
                {
                    if(i % 2) // 동 서
                    {
                        temp += 500;
                        ndir = 0;
                    }
                    else
                        ndir = 1;
                }
            }
            
            if(result <= output+100)
            {
                visit[pos.y][pos.x] = false;
                return;
            }
            
            dfs(ndir,output+temp,n,{ny,nx},board);
        }
    }
    
    visit[pos.y][pos.x] = false;
    
    return;
}
*/

int solution(vector<vector<int>> board)
{
    int n,answer = 0;
    int result = 0x7fffffff; // maximum value
    int vx[4] = {0,1,0,-1}; // 북동남서
    int vy[4] = {-1,0,1,0}; // 북동남서
    queue<Cur> q;
    
    n = (int)board.size();
    q.push({0,0,-1,0});
    board[0][0] = 1; // visit
    
    while(!q.empty())
    {
        Cur cur = q.front();
        q.pop();
        
        if(cur.y == n-1 && cur.x == n-1)
        {
            if(result > cur.output)
                result = cur.output;
            continue;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int ny = vy[i] + cur.y;
            int nx = vx[i] + cur.x;
            
            if(0 <= ny && ny < n && 0 <= nx && nx < n)
            {
                int new_dir,new_output,temp = 100;
                
                if(cur.dir == -1)
                {
                    new_dir = (i % 2 == 1 ? 0 : 1); // 0 : 동 서 , 1 : 남 북
                }
                else if(cur.dir == 0)
                {
                    if(i % 2 != 1)
                    {
                        temp += 500;
                        new_dir = 1;
                    }
                    else
                        new_dir = 0;
                }
                else // 1
                {
                    if(i % 2 != 0)
                    {
                        temp += 500;
                        new_dir = 0;
                    }
                    else
                        new_dir = 1;
                }
                
                new_output = cur.output + temp;
                
                if(board[ny][nx] == 0 || board[ny][nx] >= new_output)
                {
                    Cur ncur = {ny,nx,new_dir,new_output};
                    q.push(ncur);
                    board[ny][nx] = new_output;
                }
            }
        }
    }
        
    answer = result;
    
    return answer;
}

int main(int argc, const char * argv[])
{
    int n;
    vector<vector<int>> board;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        vector<int> tv;
        
        for(int j = 0; j < n; j++)
        {
            int temp;
            
            cin >> temp;
            tv.push_back(temp);
        }
        board.push_back(tv);
    }
    
    cout << solution(board) << endl;
    
    return 0;
}
