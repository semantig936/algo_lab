#include<stdio.h>
#include<stdlib.h>

void BFS(int** adj, int* deg, int* visited, int n, int v)
{
    visited[v] = 1;
    int* queue = (int*)malloc(n*sizeof(int));
    int front = 0;
    int rear = 0;
    queue[rear++] = v;
    int s;
    while(front!=rear)
    {
        s = queue[front];
        printf("%d ",s);
        front++;
        for(int i=0; i<deg[s]; i++)
        {
            if(visited[adj[s][i]]==0)
            {
                visited[adj[s][i]] = 1;
                queue[rear++] = adj[s][i];
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* temp = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        printf("i=%d\n",i);
        int tp = 0;
        do
        {
            scanf("%d",&temp[tp]);
            tp++;
        }
        while(temp[tp-1]!=-1);
        tp--;
        deg[i] = tp;
        adj[i] = (int*)malloc(tp*sizeof(int));
        for(int j=0; j<tp; j++)
        {
            adj[i][j] = temp[j];
        }
    }
    int* visited = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    printf("The adjacency matrix created is: \n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<deg[i]; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    printf("\nThe breadth first search is: ");
    BFS(adj, deg, visited, n, 0);
}