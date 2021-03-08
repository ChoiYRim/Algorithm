#include <vector>
#include <iostream>
#include <algorithm>

#define RANGE(x,N) (1 <= x && x <= N)

using namespace std;

struct Horse
{
    int y;
    int x;
    int dir;
};

struct Pos
{
    int y;
    int x;
    int color;
    vector<int> h;
};

int N,K;
Pos Map[16][16];
Horse horse[16];

int dy[5] = {0,0,0,-1,1};
int dx[5] = {0,1,-1,0,0};

int solution(void)
{
    int turn = 0;
    
    while(++turn <= 1000)
    {
        for(int i = 0; i < K; i++) // 0번 말부터 K-1번 말까지
        {
            int cy = horse[i].y;
            int cx = horse[i].x;
            
            int ny = cy+dy[horse[i].dir];
            int nx = cx+dx[horse[i].dir];
                        
            if(RANGE(ny,N) && RANGE(nx,N))
            {
                int index = 0;
                vector<int>& ch = Map[cy][cx].h; // 현재 말 위에 있는 말들
                vector<int>& nh = Map[ny][nx].h; // 옮길 위치에 있는 말들
                
                // 말을 옮길 시 현재 말 위에 있는 말들을 전부 포함해서 옮겨야 함
                if(Map[ny][nx].color == 0) // White
                {
                    for(int j = 0; j < ch.size() && ch[j] != i; j++)
                        index++;
                    
                    // ch의 index번째부터 모든 말을 옮겨야 함
                    for(int j = index; j < ch.size(); j++)
                        horse[ch[j]] = {ny,nx,horse[ch[j]].dir};
                    
                    nh.insert(nh.end(),ch.begin()+index,ch.end());
                    ch.erase(ch.begin()+index,ch.end());
                    
                    if(nh.size() >= 4)
                        return turn;
                }
                else if(Map[ny][nx].color == 1) // Red
                {
                    vector<int> rev;
                    
                    for(int j = 0; j < ch.size() && ch[j] != i; j++)
                        index++;
                    
                    // ch의 index번째부터 모든 말을 옮겨야 함
                    for(int j = index; j < ch.size(); j++)
                    {
                        horse[ch[j]] = {ny,nx,horse[ch[j]].dir};
                        rev.push_back(ch[j]);
                    }
                    
                    reverse(rev.begin(),rev.end());
                    nh.insert(nh.end(),rev.begin(),rev.end());
                    ch.erase(ch.begin()+index,ch.end());
                    
                    if(nh.size() >= 4)
                        return turn;
                }
                else // Blue
                {
                    if(horse[i].dir % 2 == 0)
                        horse[i].dir -= 1;
                    else
                        horse[i].dir += 1;
                    
                    ny = cy+dy[horse[i].dir];
                    nx = cx+dx[horse[i].dir];
                    
                    if(RANGE(ny,N) && RANGE(nx,N) && Map[ny][nx].color != 2)
                    {
                        i--;
                        continue;
                    }
                }
            }
            else // Blue
            {
                if(horse[i].dir % 2 == 0)
                    horse[i].dir -= 1;
                else
                    horse[i].dir += 1;
                
                ny = cy+dy[horse[i].dir];
                nx = cx+dx[horse[i].dir];
                
                if(RANGE(ny,N) && RANGE(nx,N) && Map[ny][nx].color != 2)
                {
                    i--;
                    continue;
                }
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            int color;
            cin >> color;
            Map[i][j] = {i,j,color};
        }
    }
    for(int i = 0; i < K; i++)
    {
        int y,x,dir;
        cin >> y >> x >> dir;
        horse[i] = {y,x,dir};
        Map[y][x].h.push_back(i);
    }
    
    cout << solution() << '\n';
    return 0;
}
