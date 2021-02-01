#include <iostream>
#include <algorithm>

using namespace std;

bool Row[9][10] = {0,};
bool Col[9][10] = {0,};
bool Box[9][10] = {0,};
int Map[10][10] = {0,};

inline int convertIndex(int x,int y) { return ((x/3) + 3 * (y/3)); }

int main(int argc, const char * argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i = 0; i < 81; i++) // 81단계
    {
        int row,col,num,idx;
        
        cin >> row >> col >> num;
        
        idx = convertIndex(col,row);
        if(!Map[row][col] && !Row[row][num] && !Col[col][num] && !Box[idx][num])
        {
            Map[row][col] = num;
            Row[row][num] = Col[col][num] = Box[idx][num] = true;
        }
        else
        {
            cout << i+1 << '\n';
            return 0;
        }
    }
    
    cout << -1 << '\n';
    return 0;
}
