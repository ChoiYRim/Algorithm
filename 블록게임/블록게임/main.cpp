#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define ISRANGE(x,r) (0 <= x && x < r)
#define ISPOSSIBLE(x) (x == -3 || x == -4 || x == -6 || x == -7 || x == -9)

using namespace std;

struct Pos
{
    int y;
    int x;
    bool possible; // 직사각형을 만들 수 있는가 없는가?
    int blockNum; // 블록 번호
};

int N;
vector<vector<Pos>> block;

void make_blocks(void)
{
    // 1
    vector<Pos> one;
    one.push_back({0,0,0,1});
    one.push_back({0,1,0,1});
    one.push_back({0,2,0,1});
    one.push_back({1,2,0,1});
    block.push_back(one);
    one.clear();
    
    one.push_back({0,0,0,2});
    one.push_back({0,1,0,2});
    one.push_back({1,0,0,2});
    one.push_back({2,0,0,2});
    block.push_back(one);
    one.clear();
    
    one.push_back({0,0,1,3});
    one.push_back({1,0,1,3});
    one.push_back({1,1,1,3});
    one.push_back({1,2,1,3});
    block.push_back(one);
    one.clear();
    
    one.push_back({0,0,1,4});
    one.push_back({1,0,1,4});
    one.push_back({2,0,1,4});
    one.push_back({2,-1,1,4});
    block.push_back(one);
    one.clear();
    
    // 2
    vector<Pos> two;
    two.push_back({0,0,0,5});
    two.push_back({1,0,0,5});
    two.push_back({0,1,0,5});
    two.push_back({0,2,0,5});
    block.push_back(two);
    two.clear();
    
    two.push_back({0,0,1,6});
    two.push_back({1,0,1,6});
    two.push_back({2,0,1,6});
    two.push_back({2,1,1,6});
    block.push_back(two);
    two.clear();
    
    two.push_back({0,0,1,7});
    two.push_back({1,0,1,7});
    two.push_back({1,-1,1,7});
    two.push_back({1,-2,1,7});
    block.push_back(two);
    two.clear();
    
    two.push_back({0,0,0,8});
    two.push_back({0,1,0,8});
    two.push_back({1,1,0,8});
    two.push_back({2,1,0,8});
    block.push_back(two);
    two.clear();
    
    // 3
    vector<Pos> three;
    three.push_back({0,0,1,9});
    three.push_back({1,-1,1,9});
    three.push_back({1,0,1,9});
    three.push_back({1,1,1,9});
    block.push_back(three);
    three.clear();

    three.push_back({0,0,0,10});
    three.push_back({1,0,0,10});
    three.push_back({1,1,0,10});
    three.push_back({2,0,0,10});
    block.push_back(three);
    three.clear();
    
    three.push_back({0,0,0,11});
    three.push_back({0,1,0,11});
    three.push_back({1,1,0,11});
    three.push_back({0,2,0,11});
    block.push_back(three);
    three.clear();
    
    three.push_back({0,0,0,12});
    three.push_back({1,0,0,12});
    three.push_back({1,-1,0,12});
    three.push_back({2,0,0,12});
    block.push_back(three);
    three.clear();
}

void convertToZero(vector<vector<int>>& board,int y,int x,int blockNum)
{
    int ny,nx,idx = blockNum-1;
    
    for(int i = 0; i < 4; i++)
    {
        ny = y+block[idx][i].y;
        nx = x+block[idx][i].x;
        
        if(ISRANGE(ny,N) && ISRANGE(nx,N))
            board[ny][nx] = 0;
    }
}

bool find_blocks(vector<vector<int>>& board,Pos start,int num,vector<Pos>& pv)
{
    int size = (int)block.size(),idx;
    int y = start.y; int x = start.x;
    bool check;
    vector<pair<int,int>> save;
    
    for(int i = 0; i < size; i++)
    {
        int ny,nx;
        
        idx = 0;
        check = false;
        save.push_back({y,x});
        
        for(int j = 0; j < 4; j++)
        {
            ny = y + block[i][j].y;
            nx = x + block[i][j].x;
            
            if(ISRANGE(ny, N) && ISRANGE(nx, N))
            {
                if(board[ny][nx] != num)
                {
                    check = false;
                    break;
                }
                else
                {
                    check = true;
                    idx = block[i][j].blockNum;
                    save.push_back({ny,nx});
                }
            }
            else
            {
                check = false;
                break;
            }
        }
        if(check)
        {
            int ssize = (int)save.size();
            if(ISPOSSIBLE(-idx))
                pv.push_back({save[0].first,save[0].second,1,idx});
            
            for(int j = 0; j < ssize; j++)
            {
                ny = save[j].first;
                nx = save[j].second;
                
                board[ny][nx] = -idx;
            }
            return true;
        }
        save.clear();
    }
    
    return false;
}

int solution(vector<vector<int>> board)
{
    int answer = 0,len;
    vector<Pos> pv;
    bool finish = false;
        
    N = (int)board.size();
    
    make_blocks();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(board[i][j] > 0)
                find_blocks(board,{i,j,0,0},board[i][j],pv);
                
    
    // -3 , -4 , -6 , -7 , -9만 블록 깨기 가능
    len = (int)pv.size();
    while(!finish && len > 0)
    {
        int y,x,idx,cnt = 0;
        
        for(int i = 0; i < len; i++)
        {
            bool check = true;
            
            y = pv[i].y;
            x = pv[i].x;
            idx = pv[i].blockNum;
            
            if(idx == 3)
            {
                for(int j = 0; j <= y; j++)
                {
                    if(!ISRANGE(x+1,N) || !ISRANGE(x+2,N) || (board[j][x+1] != 0 || board[j][x+2] != 0))
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    cnt++;
                    answer++;
                    convertToZero(board,y,x,idx);
                    pv.erase(pv.begin()+i);
                    break;
                }
            }
            else if(idx == 4)
            {
                for(int j = 0; j <= y+1; j++)
                {
                    if(!ISRANGE(x-1,N) || board[j][x-1] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    cnt++;
                    answer++;
                    convertToZero(board,y,x,idx);
                    pv.erase(pv.begin()+i);
                    break;
                }
            }
            else if(idx == 6)
            {
                for(int j = 0; j <= y+1; j++)
                {
                    if(!ISRANGE(x+1,N) || board[j][x+1] != 0)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    cnt++;
                    answer++;
                    convertToZero(board,y,x,idx);
                    pv.erase(pv.begin()+i);
                    break;
                }
            }
            else if(idx == 7)
            {
                for(int j = 0; j <= y; j++)
                {
                    if(!ISRANGE(x-1,N) || !ISRANGE(x-2,N) || (board[j][x-1] != 0 || board[j][x-2] != 0))
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    cnt++;
                    answer++;
                    convertToZero(board,y,x,idx);
                    pv.erase(pv.begin()+i);
                    break;
                }
            }
            else if(idx == 9)
            {
                for(int j = 0; j <= y; j++)
                {
                    if(!ISRANGE(x-1,N) || !ISRANGE(x+1,N) || (board[j][x-1] != 0 || board[j][x+1] != 0))
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    cnt++;
                    answer++;
                    convertToZero(board,y,x,idx);
                    pv.erase(pv.begin()+i);
                    break;
                }
            }
        }
        len = (int)pv.size();
        if(cnt == 0)
        {
            finish = true;
        }
    }
    
    return answer;
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<vector<int>> board = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,4,4,0,0,0},{0,0,0,0,3,0,4,0,0,0},{0,0,0,2,3,0,0,0,5,5},{1,2,2,2,3,3,0,0,0,5},{1,1,1,0,0,0,0,0,0,5}};
    
    cout << solution(board) << '\n';
    return 0;
}
