#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top = -1;
int st[64];
int TC,T;

int main(void)
{
    int idx = 0;
    char** result;
    
    scanf("%d", &TC);
    T = TC;
    result = (char **)malloc(sizeof(char *)*TC);
    for(int i = 0; i < TC; i++)
        result[i] = (char *)malloc(sizeof(char)*64);
    
    while(T--)
    {
        char str[64] = {0,};
        
        scanf("%s", str);
        strcpy(result[idx++],str);
    }
    
    T = TC;
    idx = 0;
    while(T--)
    {
        int len,answer = 1;
        
        len = (int)strlen(result[idx]);
        for(int i = 0; i < len; i++)
        {
            if(result[idx][i] == '(')
                st[++top] = '(';
            else
            {
                if(top < 0 || st[top] != '(')
                {
                    printf("NO\n");
                    answer = 0;
                    break;
                }
                st[top--] = 0;
            }
        }
        if(answer)
        {
            if(top > -1)
                printf("NO\n");
            else
                printf("YES\n");
        }
        
        top = -1;
        memset((int *)st,0,sizeof(st));
        idx++;
    }
    return 0;
}
