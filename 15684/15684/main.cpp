#include <iostream>

using namespace std;

#define N_MAX 10 + 5
#define H_MAX 30 + 5
#pragma warning(disable:4996)

// global
int ladder_map[H_MAX][N_MAX] = { 0 };
int N, M, H;
 
// 정답이 되는지 출력
int is_answer()
{
    for (int col = 1; col <= N; col++)
    {
        int now_col = col;
        for (int row = 1; row <= H; row++)
        {
            int left = ladder_map[row][now_col - 1];
            int right = ladder_map[row][now_col];
 
            if (left)  now_col--;
            if (right) now_col++;
        }
        if (now_col != col) return 0;
    }
    return 1;
}
 
// 사다리를 놓는다. dfs 방식으로 설치하고 완료되면 종료
int make_ladder(int _end_depth, int _now_depth, int _row, int _col)
{
    if (_now_depth == _end_depth)
    {
        if (is_answer())
        {
            printf("%d", _now_depth);
            exit(0);
        }
        return 0;
    }
    int row = _col + 1 > H ? _row + 1 : _row;
    int col = _col + 1 > H ? 0 : _col + 1;
    for (; row <= H; row++)
    {
        for (; col <= N; col++)
        {
            if (ladder_map[row][col - 1] || ladder_map[row][col] || ladder_map[row][col + 1]) continue;
            ladder_map[row][col] = 1;
            make_ladder(_end_depth, _now_depth + 1, row, col);
            ladder_map[row][col] = 0;
        }
        col = 1;
    }
    return 0;
}
 
int main()
{
    scanf("%d %d %d", &N, &M, &H);
    for (int m_idx = 0; m_idx < M; m_idx++)
    {
        int a, b; scanf("%d %d", &a, &b);
        ladder_map[a][b] = 1;
    }
    if (is_answer())
    {
        printf("0"); return 0;
    }
    for (int plus = 1; plus <= 3; plus++)
    {
        for (int row = 1; row <= H; row++)
        {
            for (int col = 1; col <= N; col++)
            {
                if (ladder_map[row][col - 1] || ladder_map[row][col] || ladder_map[row][col + 1]) continue;
                ladder_map[row][col] = 1;
                make_ladder(plus, 1, row, col);
                ladder_map[row][col] = 0;
            }
        }
    }
    printf("-1"); return 0;
}
