#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define RANGE(x,y) ((0 <= x && x < N) && (0 <= y && y < N))

using namespace std;

int N;
vector<int> result;
vector<vector<int>> v;
vector<vector<bool>> visit;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int cnt = 0;

void DFS(int x,int y)
{
    visit[y][x] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i],ny = y+dy[i];
        if(RANGE(nx,ny) && !visit[ny][nx] && v[ny][nx])
        {
            cnt++;
            DFS(nx,ny);
        }
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    v = vector<vector<int>>(36,vector<int>(36,0));
    visit = vector<vector<bool>>(36,vector<bool>(36,0));
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str = "";
        cin >> str;
        for(int j = 0; j < (int)str.length(); j++)
            v[i][j] = str[j]-'0';
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(v[i][j] && !visit[i][j])
            {
                cnt = 1;
                DFS(j,i);
                result.push_back(cnt);
            }
        }
    }
    
    sort(result.begin(),result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < (int)result.size(); i++)
        cout << result[i] << '\n';
    return 0;
}
