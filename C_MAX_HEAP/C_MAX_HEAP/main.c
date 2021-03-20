#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100
#define HEAP_EMPTY(n) (!n)
#define HEAP_FULL(n) (n == MAX_SIZE-1)

int heap[MAX_SIZE],idx = 0;

void addHeap(int value)
{
    if(HEAP_FULL(idx))
        return;

    int i = ++idx;
    while((i != 1) && (value > heap[i/2]))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = value;
}

int deleteHeap(void)
{
    if(HEAP_EMPTY(idx))
        return INT_MIN;
    int parent = 1,child = 2;
    int item = heap[1],temp = heap[idx--];

    while(child <= idx)
    {
        if(child < idx && heap[child] < heap[child+1])
            child++;
        if(temp >= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = temp;
    return item;
}

int main(void)
{
    int data[98];
    for(int i = 0; i < 98; i++)
        data[i] = 98-i;

    for(int i = 0; i < 98; i++)
        addHeap(data[i]);
    
    while(!HEAP_EMPTY(idx))
        printf("heap number : %d\n", deleteHeap());

    return 0;
}
