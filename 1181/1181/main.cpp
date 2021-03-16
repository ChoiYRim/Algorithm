#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20000+2

//typedef struct _str
//{
//    char string[64];
//    int len;
//}String;

int N;
char strings[MAX][64] = {0,};
char sorted[MAX][64] = {0,};

void merge(int left,int mid,int right)
{
    int l,r,idx;
    l = left;
    r = mid+1;
    idx = left;
    
    while(l <= mid && r <= right)
    {
        int len1 = (int)strlen(strings[l]);
        int len2 = (int)strlen(strings[r]);
        
        if(len1 < len2)
        {
            memset((char *)sorted[idx],0,sizeof(sorted[idx]));
            strcpy(sorted[idx++],strings[l++]);
        }
        else if(len1 > len2)
        {
            memset((char *)sorted[idx],0,sizeof(sorted[idx]));
            strcpy(sorted[idx++],strings[r++]);
        }
        else
        {
            if(strcmp(strings[l],strings[r]) < 0)
                strcpy(sorted[idx++],strings[l++]);
            else
                strcpy(sorted[idx++],strings[r++]);
        }
    }
    
    if(l <= mid)
    {
        while(l <= mid)
        {
            memset((char *)sorted[idx],0,sizeof(sorted[idx]));
            strcpy(sorted[idx++],strings[l++]);
        }
    }
    else
    {
        while(r <= right)
        {
            memset((char *)sorted[idx],0,sizeof(sorted[idx]));
            strcpy(sorted[idx++],strings[r++]);
        }
    }
    
    for(int i = left; i <= right; i++)
    {
        memset((char *)strings[i],0,sizeof(strings[i]));
        strcpy(strings[i],sorted[i]);
    }
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

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s", strings[i]);
    
    merge_sort(0,N-1);
    printf("%s\n", strings[0]);
    for(int i = 1; i < N; i++)
    {
        if(strcmp(strings[i],strings[i-1]) != 0)
            printf("%s\n", strings[i]);
    }
    return 0;
}
