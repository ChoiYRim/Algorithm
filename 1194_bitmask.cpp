#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Pos
{
    int y;
    int x;
    int cnt;
    int keys;
};

int N,M;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<string> v;
bool visit[(1 << 6)][50][50] = {0,}; // (key가 존재하는 경우의 수)(Y)(X)

inline bool isLowerCase(char ch) { return (ch >= 'a' && ch <= 'f'); }

inline bool isUpperCase(char ch) { return (ch >= 'A' && ch <= 'F'); }

inline bool isRange(int x,int y) { return ((x >= 0 && x < M) && (y >= 0 && y < N)); }

inline bool isThereKey(int idx,int key) { return (key & (1 << idx)); }

int addKey(int idx,int& key)
{
    int newKey = (key | (1 << idx));
    return newKey;
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Pos start;
    queue<Pos> q;
    
    cin >> N >> M;
    start.keys = 0;
    for(int i = 0; i < N; i++)
    {
        string str = "";
        cin >> str;
        for(int j = 0; j < M; j++)
        {
            if(str[j] == '0')
            {
                start.y = i;
                start.x = j;
                start.cnt = 0;
            }
        }
        v.push_back(str);
    }
    
    q.push(start);
    visit[0][start.y][start.x] = true;
    while(!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        int key = q.front().keys;
        
        q.pop();
        
        if(v[y][x] == '1')
        {
            cout << cnt << '\n';
            return 0;
        }
        for(int i = 0; i < 4; i++)
        {
            int ny = y+dy[i];
            int nx = x+dx[i];
            
            if(isRange(nx,ny) && !visit[key][ny][nx] && v[ny][nx] != '#')
            {
                if(isLowerCase(v[ny][nx]))
                {
                    int nextKey = addKey(v[ny][nx]-'A',key);
                    
                    if(!visit[nextKey][ny][nx])
                    {
                        visit[key][ny][nx] = true;
                        visit[nextKey][ny][nx] = true;
                        q.push({ny,nx,cnt + 1,nextKey});
                    }
                    
                }
                else if(isUpperCase(v[ny][nx]))
                {
                    if(isThereKey(v[ny][nx]-'A',key))
                    {
                        visit[key][ny][nx] = true;
                        q.push({ny,nx,cnt + 1,key});
                    }
                }
                else
                {
                    visit[key][ny][nx] = true;
                    q.push({ny,nx,cnt+1,key});
                }
            }
        }
    }
        
    cout << -1 << '\n';
    return 0;
}
