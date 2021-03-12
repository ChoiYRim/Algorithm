#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define RANGE(x) (0 <= x && x < 8)

using namespace std;

int N = 0,result = 0;
vector<vector<int>> Map; // 0 : empty , 1 : black , 2 : white
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};

int DFS(int dir,int y,int x,int num)
{
    if(!RANGE(y) || !RANGE(x))
        return 0;
    if(Map[y][x] == 0)
        return 0;
    if(Map[y][x] == 1)
        return num;
    if(Map[y][x] == 2)
        num++;
    
    return DFS(dir,y+dy[dir],x+dx[dir],num);
}

void check(int y,int x)
{
    int cnt = 0;
    // Map[y][x] 가 빈칸이며 여기에 검은색 돌을 놓았을 때 바꿀 수 있는 흰색 돌들의 개수
    for(int i = 0; i < 8; i++)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        // 갈 수 있는 방향이라면
        if(RANGE(ny) && RANGE(nx) && Map[ny][nx] != 1)
        {
            //result = max(result,DFS(i,ny,nx,0));
            cnt += DFS(i,ny,nx,0);
            result = max(result,cnt);
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    for(int i = 0; i < 8; i++)
    {
        cin >> str;
        vector<int> v;
        for(int j = 0; j < 8; j++)
        {
            if(str[j] == '.')
            {
                N++;
                v.push_back(0);
            }
            else if(str[j] == 'B')
                v.push_back(1);
            else
                v.push_back(2);
        }
        Map.push_back(v);
        str.clear();
    }
    
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(!Map[i][j])
            {
                check(i,j);
            }
        }
    }
    
    cout << result << '\n';
    return 0;
}
