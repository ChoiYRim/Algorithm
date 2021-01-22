#include <set>
#include <string>
#include <vector>
#include <iostream>

#define ISRANGE(x,R) (0 <= x && x < R)

using namespace std;

// 라이언 R , 무지 M , 어피치 A , 프로도 F , 네오 N , 튜브 T , 제이지 J , 콘 C
// 판의 높이 m , 판의 너비 n

int vy[3] = {0,1,1}; // 동쪽 , 남쪽 , 남동쪽
int vx[3] = {1,0,1}; // "

int count(int m,int n,vector<string> board,set<pair<int,int>> &s)
{
    for(int i = 0; i < m; i++) // 높이
    {
        for(int j = 0; j < n; j++) // 너비
        {
            bool check = true;
            char ch = board[i][j];
            vector<pair<int,int>> v;
            
            if(ch == '0')
                continue;
            
            v.push_back({i,j});
            for(int k = 0; k < 3; k++)
            {
                int ny = i + vy[k];
                int nx = j + vx[k];
                
                if(ISRANGE(ny,m) && ISRANGE(nx,n))
                {
                    if(ch != board[ny][nx])
                    {
                        check = false;
                        break;
                    }
                    v.push_back({ny,nx});
                }
                else
                {
                    check = false;
                    break;
                }
            }
            if(check && (int)v.size() == 4)
            {
                for(int i = 0; i < 4; i++)
                {
                    set<pair<int,int>>::iterator it = s.find(v[i]);
                    if(it == s.end())
                    {
                        s.insert(v[i]);
                    }
                }
            }
        }
    }
    
    return (int)s.size();
}

void mapClear(int m,int n,vector<string> &board,set<pair<int,int>> &s)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '0')
                continue;
            
            pair<int,int> p = {i,j};
            set<pair<int,int>>::iterator it = s.find(p);
            if(it != s.end())
                board[i][j] = '0';
        }
    }
    
    s.clear();
    
    int r = m-1,c,save;
    
    while(r > 0)
    {
        for(c = 0; c < n; c++)
        {
            if(board[r][c] == '0')
            {
                for(save = r-1; save >= 0 && board[save][c] == '0'; save--);
                if(save >= 0)
                {
                    board[r][c] = board[save][c];
                    board[save][c] = '0';
                }
            }
        }
        r--;
    }
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0,ret = 0;
    set<pair<int,int>> s;
    
    s.clear();
    while((ret = count(m,n,board,s)) > 0)
    {
        mapClear(m,n,board,s);
        answer += ret;
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //int m = 6,n = 6;
    //vector<string> board = {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"};
    
    int m = 6,n = 6;
    vector<string> board = {"AABBEE","AAAEEE","VAAEEV","AABBEE","AACCEE","VVCCEE"};
    
    cout << solution(m,n,board) << '\n';
    return 0;
}
