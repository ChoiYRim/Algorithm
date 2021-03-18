#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(x,y) (x < y ? x : y)
#define max(x,y) (x > y ? x : y)

#define INDEX 300000+1

typedef long long ll;

ll N,M;
ll gem[INDEX];

int main(void)
{
    ll left,right,mid,result = LLONG_MAX;
    
    right = 0;
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%lld", &gem[i]);
        right = max(right,gem[i]);
    }
    
    left = 1;
    while(left <= right)
    {
        ll cnt = 0;
        mid = (left+right)/2; // 가장 큰 질투심이 M이다
        for(int i = 0; i < M; i++)
        {
            cnt += gem[i]/mid;
            if(gem[i]%mid != 0)
                cnt++;
        }
        
        if(cnt <= N)
        {
            right = mid-1;
            result = min(result,mid);
        }
        else
            left = mid+1;
    }
    
    printf("%lld\n", result);
    return 0;
}
