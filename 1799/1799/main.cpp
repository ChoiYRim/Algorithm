// 출처 : https://j2wooooo.tistory.com/80

#include <iostream>
#include <algorithm>

using namespace std;
 
int N;
int ans[2]; // 흑색에 비숍을 두는 경우 / 백색에 비숍을 두는 경우에서 각각의 최대값
int Map[11][11];
int l[20],r[20];
 
void Check(int row, int col,int count, int color)
{
    if(col >= N)
    {
        row++; // 다음 행으로 이동
        if(col%2 == 0) // 같은 color 지역으로 이동하기 위해서
            col = 1;
        else // 위와 동일
            col = 0;
    }
    
    if(row >= N)
    {
        ans[color] = max(ans[color], count);
        return;
    }
 
    // 비숍을 놓을 수 있으면서 오른쪽 아래를 향하는 대각선과 오른쪽 위를 향하는 대각선 조건을 모두 충족
    if(Map[row][col] && !l[col - row + N - 1] && !r[row + col])
    {
        l[col - row + N - 1] = r[row + col] = 1; // backtracking
        Check(row, col+2, count + 1, color); // 같은 color끼리 이동하기 위해 col+2
        l[col - row + N - 1] = r[row + col] = 0;
    }
    
    Check(row, col+2, count, color);
}
 
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Map[i][j];
 
    Check(0, 0, 0, 0); // 흑색
    Check(0, 1, 0, 1); // 백색
 
    cout << ans[0] + ans[1];
    return 0;
}
