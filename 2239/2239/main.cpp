#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

// visit 체크용 [행,열의 개수][1~9 숫자 개수]
bool Row[9][10] = {0,};
bool Column[9][10] = {0,};
bool Box[9][10] = {0,};

// 9 X 9
int Map[10][10];

void printResult(void)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
            cout << Map[i][j];
        cout << '\n';
    }
}

inline int convertIndex(int x,int y) { return (x / 3 + (y / 3) * 3); }

void DFS(int depth)
{
    if(depth == 81)
    {
        printResult();
        exit(0); // DFS원리 상 가장 작은 값이 먼저 나오므로 한 번 출력하고 끝
    }
    
    int row = depth / 9;
    int col = depth % 9;
    
    if(Map[row][col]) // 이미 숫자가 있으면 Pass
    {
        DFS(depth+1);
    }
    else
    {
        for(int i = 1; i <= 9; i++) // 숫자들
        {
            if(!Row[row][i] && !Column[col][i] && !Box[convertIndex(col,row)][i])
            {
                Row[row][i] = true;
                Column[col][i] = true;
                Box[convertIndex(col,row)][i] = true;
                Map[row][col] = i;
                
                DFS(depth+1);
                
                Row[row][i] = false;
                Column[col][i] = false;
                Box[convertIndex(col,row)][i] = false;
                Map[row][col] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset((int *)Map,0,sizeof(Map));
    
    for(int i = 0; i < 9; i++)
    {
        string str;
        cin >> str;
        
        for(int j = 0; j < 9; j++)
        {
            int num = str[j] - '0';
            if(num)
            {
                Row[i][num] = true;
                Column[j][num] = true;
                Box[convertIndex(j,i)][num] = true;
            }
            Map[i][j] = num;
        }
    }
    
    DFS(0);
    return 0;
}
