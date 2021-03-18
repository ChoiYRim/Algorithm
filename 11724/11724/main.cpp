//#include <stdio.h>
//#include <stdlib.h>
//
//int N,M,cnt = 0;
//int graph[1001][1001] = {0,};
//int visit[1001] = {0,};
//
//void DFS(int cur)
//{
//    for(int i = 1; i <= N; i++)
//    {
//        if(!visit[i] && graph[cur][i])
//        {
//            visit[i] = 1;
//            DFS(i);
//        }
//    }
//}
//
//int main(void)
//{
//    scanf("%d %d", &N, &M);
//    for(int i = 0; i < M; i++)
//    {
//        int u,v;
//        scanf("%d %d", &u, &v);
//        graph[u][v] = 1;
//        graph[v][u] = 1;
//    }
//
//    for(int i = 1; i <= N; i++)
//    {
//        if(visit[i])
//            continue;
//        cnt++;
//        visit[i] = 1;
//        DFS(i);
//    }
//
//    printf("%d\n", cnt);
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int N,M;
int graph[1001][1001] = {0,};
int* queue;
int front,rear;

int isEmpty(void)
{
    if(front == rear)
        return 1;
    return 0;
}

int isFull(void)
{
    int tmp = (rear+1)%M;
    if(front == tmp)
        return 1;
    return 0;
}

void addQ(int value)
{
    if(isFull())
        return;
    rear = (rear+1)%M;
    queue[rear] = value;
}

int deleteQ(void)
{
    if(isEmpty())
        return -1;
    front = (front+1)%M;
    return queue[front];
}

int main(void)
{
    int cnt = 0;
    int visit[1001] = {0,};
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    for(int i = 1; i <= N; i++)
    {
        if(visit[i])
            continue;
        
        visit[i] = 1;
        cnt++;
        
        queue = (int *)calloc(M,sizeof(int));
        front = -1; rear = -1;
        
        addQ(i);
        while(!isEmpty())
        {
            int cur = deleteQ();
            if(cur != -1)
            {
                for(int j = 1; j <= N; j++)
                {
                    if(!visit[j] && graph[cur][j])
                    {
                        visit[j] = 1;
                        addQ(j);
                    }
                }
            }
        }
        
        free(queue);
    }
    
    printf("%d\n", cnt);
    return 0;
}
