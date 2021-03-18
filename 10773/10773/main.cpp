#include <stdio.h>

int K;
int st[100008];
int top = -1;

int main(void)
{
    int sum = 0;
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        int num;
        scanf("%d", &num);
        
        if(!num)
            st[top--] = 0;
        else
            st[++top] = num;
    }
    
    for(;top > -1; top--)
        sum += st[top];
    printf("%d\n", sum);
    return 0;
}
