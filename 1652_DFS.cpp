#include <string>
#include <iostream>

using namespace std;

int N,width,height;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int place[100][100] = {0,};

inline bool isRange(int y,int x) { return ((y >= 0 && y < N) && (x >= 0 && x < N)); }

inline bool empty(int y,int x) { return !place[y][x]; }

void hDfs(int depth,int emptyCnt)
{
    if(depth >= N*N)
    {
        if(emptyCnt >= 2)
            width++;
        return;
    }
    
    int y = depth/N;
    int x = depth%N;
    
    if(!x)
    {
        if(emptyCnt >= 2)
            width++;
        emptyCnt = 0;
    }
    if(!empty(y,x))
    {
        if(emptyCnt >= 2)
            width++;
        hDfs(depth+1,0);
        return;
    }
    
    emptyCnt++;
    hDfs(depth+1,emptyCnt);
}

void vDfs(int depth,int emptyCnt)
{
    if(depth >= N*N)
    {
        if(emptyCnt >= 2)
            height++;
        return;
    }
    
    int y = depth%N;
    int x = depth/N;
    
    if(!y)
    {
        if(emptyCnt >= 2)
            height++;
        emptyCnt = 0;
    }
    if(!empty(y,x))
    {
        if(emptyCnt >= 2)
            height++;
        vDfs(depth+1,0);
        return;
    }
    
    emptyCnt++;
    vDfs(depth+1,emptyCnt);
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    width = height = 0;
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        string str = "";
        cin >> str;
        for(int j = 0; j < (int)str.length(); j++)
        {
            if(str[j] == 'X')
                place[i][j] = 1;
        }
    }
    
    hDfs(0,0); vDfs(0,0);
    cout << width << " " << height << '\n';
    return 0;
}
