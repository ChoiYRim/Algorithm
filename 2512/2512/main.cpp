#include <stdio.h>
#include <stdlib.h>

#define INDEX 10000+1
#define MAX 1000000000
#define max(x,y) (x < y ? y : x)

int N,M;
int asset[INDEX] = {0,};

int main(void)
{
    int last = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &asset[i]);
        last = max(last,asset[i]);
    }
    scanf("%d", &M);
    
    long long left = 0,right = last,mid,result = 0;
    while(left <= right)
    {
        long long num = 0;
        mid = (left+right)/2;
        for(int i = 0; i < N; i++)
            num += (asset[i] <= mid ? asset[i] : mid);
        
        if(num > M)
            right = mid-1;
        else
        {
            left = mid+1;
            result = max(result,mid);
        }
    }
    
    printf("%lld\n", result);
    return 0;
}
