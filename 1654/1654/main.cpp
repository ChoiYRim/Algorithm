#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000+1
#define max(x,y) (x > y ? x : y)

int N,K;
long long arr[MAX] = {0,};
long long sorted[MAX] = {0,};

void merge(int left,int mid,int right)
{
    int l,r,idx;
    
    l = left;
    idx = left;
    r = right;
    while(l <= mid && r <= right)
    {
        if(arr[l] < arr[r])
            sorted[idx++] = arr[l++];
        else
            sorted[idx++] = arr[r++];
    }
    
    if(l <= mid)
        while(l <= mid)
            sorted[idx++] = arr[l++];
    else
        while(r <= right)
            sorted[idx++] = arr[r++];
    
    for(int i = left; i <= right; i++)
        arr[i] = sorted[i];
}

void merge_sort(int left,int right)
{
    int mid;
    if(left < right)
    {
        mid = (left+right)/2;
        merge_sort(left,mid);
        merge_sort(mid+1,right);
        merge(left,mid,right);
    }
}

long long binary_search(long long left,long long right)
{
    long long num,mid = -1;
    long long m = 0;
    
    while(left <= right)
    {
        num = 0;
        mid = (left+right)/2;
        
        for(int i = 0; i < K; i++)
            num += (arr[i]/mid);
        if(num < N) // 너무 크게 자름
            right = mid-1;
        else
        {
            left = mid+1;
            m = max(m,mid);
        }
    }
    
    return m;
}

int main(void)
{
    scanf("%d %d", &K, &N);
    for(int i = 0; i < K; i++)
        scanf("%lld", &arr[i]);
    
    //merge_sort(0,K-1); // sort first
    printf("%lld\n", binary_search(0,LLONG_MAX));
    return 0;
}
