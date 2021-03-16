#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000+1

typedef struct _pos
{
    int x;
    int y;
}Pos;

int N;
Pos sorted[MAX];

void merge(Pos* point,int left,int mid,int right)
{
    int l,r,idx; // left , right , mid
    l = left;
    r = mid+1;
    idx = left;
    
    // 정렬
    while(l <= mid && r <= right)
    {
        if(point[l].x < point[r].x)
        {
            sorted[idx] = point[l];
            idx++; l++;
        }
        else if(point[l].x == point[r].x)
        {
            if(point[l].y < point[r].y)
            {
                sorted[idx] = point[l];
                idx++; l++;
            }
            else
            {
                sorted[idx] = point[r];
                idx++; r++;
            }
        }
        else
        {
            sorted[idx] = point[r];
            idx++; r++;
        }
    }
    
    // 남아있는 값들 일괄 복사
    if(l <= mid)
    {
        for(int i = l; i <= mid; i++)
        {
            sorted[idx] = point[i];
            idx++;
        }
    }
    else
    {
        for(int i = r; i <= right; i++)
        {
            sorted[idx] = point[i];
            idx++;
        }
    }
    
    // 값들 다시 point배열에 옮기기
    for(int i = left; i <= right; i++)
        point[i] = sorted[i];
}

void merge_sort(Pos* point,int left,int right)
{
    int mid;
    
    if(left < right)
    {
        mid = (left+right)/2;
        merge_sort(point,0,mid);
        merge_sort(point,mid+1,right);
        merge(point,left,mid,right);
    }
}

int main(void)
{
    Pos point[MAX];

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        point[i].x = x; point[i].y = y;
    }
    
    merge_sort(point,0,N-1);
    for(int i = 0; i < N; i++)
    {
        printf("%d %d\n", point[i].x, point[i].y);
    }
    return 0;
}
