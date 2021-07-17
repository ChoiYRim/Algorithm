#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int R,C;
vector<string> v;
vector<bool> visit;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

inline bool isRange(int x,int y) { return ((0 <= x && x < C) && (0 <= y && y < R)); }

inline int getIndex(char c) { return c-'A'; }

int DFS(int x,int y)
{
    int result = 0;
    
    for(int i = 0; i < 4; i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(!isRange(nx,ny))
            continue;
        
        int idx = getIndex(v[ny][nx]);
        
        if(visit[idx])
            continue;
        
        visit[idx] = true;
        result = max(result,DFS(nx,ny));
        visit[idx] = false;
    }
    
    return result+1;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    visit = vector<bool>(26,false);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++)
    {
        string str = "";
        cin >> str;
        v.push_back(str);
    }
    
    visit[getIndex(v[0][0])] = true;
    cout << DFS(0,0) << '\n';
    return 0;
}
