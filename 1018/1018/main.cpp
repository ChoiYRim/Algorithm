#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 987654321
#define MIN(x1,x2) (x1 < x2 ? x1 : x2)
#define RANGE(x,R) (0 <= x && x < R)
//typedef _Bool bool;

int M,N;
int result = INF;
bool Map[64][64]; // 0 : white , 1 : black

int DFS(int y,int x)
{
    bool w = 0,b = 1;
    int convert_w = 0,convert_b = 0;
    
    // 맨 좌측 맨 위가 흰색(0) 일 때
    for(int i = y; i < y+8; i++)
    {
        for(int j = x; j < x+8; j++)
        {
            if(Map[i][j] != w)
                convert_w++;
            w = !w;
        }
        w = !w;
    }
    
    // 맨 좌측 맨 위가 흑색(0) 일 때
    for(int i = y; i < y+8; i++)
    {
        for(int j = x; j < x+8; j++)
        {
            if(Map[i][j] != b)
                convert_b++;
            b = !b;
        }
        b = !b;
    }
    
    return MIN(convert_w,convert_b);
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        char str[64] = {0,};
        scanf("%s", str);
        for(int j = 0; j < M; j++)
        {
            if(str[j] == 'W')
                Map[i][j] = 0;
            else
                Map[i][j] = 1;
        }
    }
    
    for(int i = 0; i <= N-8; i++)
    {
        for(int j = 0; j <= M-8; j++)
        {
            result = MIN(result,DFS(i,j));
        }
    }
    
    printf("%d\n", result);
    return 0;
}
