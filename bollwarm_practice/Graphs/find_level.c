#include<stdio.h>
#include<stdlib.h>

void BFS(int** adj, int* deg ,int n , int v, int key, int* visited, int* level)
{
    //int level = 0;
    visited[v] = 1;
    int* queue = (int*)malloc(n*sizeof(int));
    int front = 0;
    int rear = 0;
    queue[rear++] = v;
    level[v] = 1;
    while(front!=rear)
    {
        int s = queue[front];
        front++;
        for(int i=0; i<deg[s]; i++)
        {
            if(visited[adj[s][i]]==0)
            {
                visited[adj[s][i]] = 1;
                queue[rear++] = adj[s][i];
                level[adj[s][i]] = level[s] + 1;
            }
        }
        printf("\nCurrent situation of the queue: ");
        for(int i=front; i<rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    int* deg = (int*)malloc(n*sizeof(int));
    printf("Enter the degree of each node: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&deg[i]);
    }
    int** adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
    } 
    printf("Enter the nodes connected to the given node one by one: ");
    for(int i=0; i<n; i++)
    {
        printf("i=%d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }   
    }
    //just a customary check - to ensure that the crappy matrix has been created okay
    for(int i=0; i<n; i++)
    {
        printf("\n%d->",i);
        for(int j=0; j<deg[i]; j++)
        {
            printf("%d ",adj[i][j]);
        }
    }
    int key;
    printf("\nEnter the value whose level you want to find: ");
    scanf("%d",&key);
    int* visited = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
    //I can't return the level of the value simply, so I'll store the level of all the values in an array.
    int* level = (int*)malloc(n*sizeof(int));
    BFS(adj, deg, n, 0, key, visited, level);
    printf("\nI don't care, so I'm printing the values of all the nodes.");
    for(int i=0; i<n; i++)
    {
        printf("\nThe level of %d is: %d",i,level[i]);
    }
    return 0;
}