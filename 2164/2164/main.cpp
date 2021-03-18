#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QSIZE 500000

int N;
int front,rear,size;
int* queue;

int isEmpty(void)
{
    if(front == rear)
        return 1;
    return 0;
}

int isFull(void)
{
    int tmp = (rear+1)%N;
    if(front == tmp)
        return 1;
    return 0;
}

void addQ(int num)
{
    if(isFull())
    {
        printf("Queue is full\n");
        return;
    }
    
    size++;
    rear = (rear+1)%N;
    queue[rear] = num;
}

int deleteQ(void)
{
    if(isEmpty())
    {
        printf("Queue is Empty\n");
        return -1;
    }
    
    size--;
    front = (front+1)%N;
    return queue[front];
}

int main(void)
{
    scanf("%d", &N);
    
    queue = (int *)malloc(sizeof(int)*N);
    size = 0;
    front = rear = -1;
    for(int i = 0; i < N; i++)
        addQ(i+1);
    
    while(size != 1)
    {
        deleteQ();
        if(size == 1)
            break;
        int next = deleteQ();
        addQ(next);
    }
    
    printf("%d\n", deleteQ());
    free(queue);
    return 0;
}

