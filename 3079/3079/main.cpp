#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)

long long N,M;
long long arr[100000+1];

int main(void)
{
    long long large = -1;
    
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        large = max(large,arr[i]);
    }
    
    long long left = 1,right = M*large,mid,result = LLONG_MAX;
    while(left <= right)
    {
        mid = (left+right)/2;
        long long sum = 0;
        
        for(int i = 0; i < N; i++)
            sum += (mid / arr[i]);
        
        if(sum >= M)
        {
            result = min(result,mid);
            right = mid-1;
        }
        else
            left = mid+1;
    }
    
    printf("%lld\n", result);
    return 0;
}
