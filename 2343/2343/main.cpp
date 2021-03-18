// 가장 짧은 길이의 블루레이 ?

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define min(x,y) (x < y ? x : y)
#define max(x,y) (x < y ? y : x)

int N,M;
long long arr[100001];

int main(void)
{
    long long left,right,mid;
    
    left = right = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &arr[i]);
        right += arr[i];
        left = max(left,arr[i]);
    }
    
    while(left <= right)
    {
        int cnt = 0;
        long long temp = 0;
        mid = (left + right) / 2; // 블루레이 값 설정
        
        for(int i = 0; i < N; i++)
        {
            if(temp+arr[i] > mid)
            {
                temp = 0;
                cnt++;
            }
            temp += arr[i];
        }
        if(temp != 0)
            cnt += 1;
        
        if(cnt <= M)
            right = mid-1;
        else if(cnt > M)
            left = mid+1;
    }
    
    printf("%lld\n", left);
    return 0;
}
