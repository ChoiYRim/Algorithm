#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _client
{
    int age;
    int order;
    char name[128];
}Client;

int N;
Client* client;
Client* sorted;

void merge(int left,int mid,int right)
{
    int l,r,idx;
    
    l = left;
    idx = left;
    r = mid+1;
    while(l <= mid && r <= right)
    {
        if(client[l].age < client[r].age)
            sorted[idx++] = client[l++];
        else if(client[l].age > client[r].age)
            sorted[idx++] = client[r++];
        else
        {
            if(client[l].order < client[r].order)
                sorted[idx++] = client[l++];
            else
                sorted[idx++] = client[r++];
        }
    }
    
    if(l <= mid)
        while(l <= mid)
            sorted[idx++] = client[l++];
    else
        while(r <= right)
            sorted[idx++] = client[r++];
    
    for(int i = left; i <= right; i++)
        client[i] = sorted[i];
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
    client = (Client *)malloc(sizeof(Client)*N);
    sorted = (Client *)malloc(sizeof(Client)*N);
    for(int i = 0; i < N; i++)
    {
        client[i].order = i+1;
        scanf("%d %s", &client[i].age, client[i].name);
    }
    
    merge_sort(0,N-1);
    for(int i = 0; i < N; i++)
        printf("%d %s\n", client[i].age, client[i].name);
    
    free(client);
    free(sorted);
    return 0;
}
