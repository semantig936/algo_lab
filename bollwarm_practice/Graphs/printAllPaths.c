#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printStack(int* stack, int top)
{
    for(int i=0; i<top-1; i++)
    {
        printf("%d->",stack[i]);
    }
    printf("%d\n",stack[top-1]);
}

void DFS(int** adj, int* deg, int u, int v, int* stack, int* top, bool* visited)
{
    stack[(*top)++] = u;
    visited[u] = true;
    if(u==v)
    {
        printStack(stack, *top); //I'll define a function afterwards
    }
    for(int i=0; i<deg[u]; i++)
    {
        if(!visited[adj[u][i]])
        {
            DFS(adj, deg, adj[u][i], v, stack, top, visited);
        }
    }
    // we are reversing the action we have taken earlier
    visited[u] = false;
    (*top)--;
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* temp = (int*)malloc(n*sizeof(int));
    printf("Enter all the connected vertices for each of the given vertices(enter -1 to exit:");
    for(int i=0; i<n; i++)
    {
        printf("\n%d: ",i);
        int tp = 0;
        do
        {
            scanf("%d",&temp[tp++]);
        }
        while (temp[tp-1] != -1);
        deg[i] = tp - 1;
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
        for(int j=0; j<deg[i]; j++)
        {
            adj[i][j] = temp[j];
        }
    }
    bool* visited = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    int src, dest;
    printf("Enter the source and destination: ");
    scanf("%d %d",&src,&dest);
    int* stack = (int*)malloc(n*sizeof(int));
    int top = 0;
    DFS(adj, deg, src, dest, stack, &top, visited);
    return 0;
}