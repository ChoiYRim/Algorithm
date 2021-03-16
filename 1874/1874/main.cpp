#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000+1

int v[MAX] = {0,};
int st[MAX] = {0,};
char result[200002] = {0,};
int N,cur = 1,top = -1;

int main(void)
{
    int i,len = 0;
    
    scanf("%d", &N);
    for(i = 0; i < N; i++)
        scanf("%d", &v[i]);
    
    i = 0;
    while(i < N)
    {
        if(cur <= N)
        {
            st[++top] = cur++;
            result[len++] = '+';
        }
        else // cur > N
        {
            if(top < 0 || i >= N || st[top] != v[i])
            {
                printf("NO\n");
                return 0;
            }
        }
        
        while(top > -1 && i < N && st[top] == v[i])
        {
            i++;
            st[top--] = 0;
            result[len++] = '-';
        }
    }
    
    for(i = 0; i < len; i++)
        printf("%c\n", result[i]);
    return 0;
}
