#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Note: In this case, all the paths possible from the sorce to the vertex(as entered by user) will be printed
void printPath(int* stack, int top)
{
    for(int i=0; i<top-1; i++)
    {
        printf("%d->",stack[i]);
    }
    printf("%d\n",stack[top-1]);
}

void path(int** adj, int* deg, int n, int u, int v, bool* visited, int* stack, int top)
{
    visited[u] = true;
    stack[top++] = u;
    if(u==v)
    {
        printPath(stack, top);
    }
    for(int i=0; i<deg[u]; i++)
    {
        if(!visited[adj[u][i]])
        {
            path(adj, deg, n, adj[u][i], v, visited, stack, top);
        }
    }
    visited[u] = false;
    top--;
}

int main()
{
    int n;
    printf("Enter the number of vertices in a graph: ");
    scanf("%d",&n);
    int* deg = (int*)malloc(n*sizeof(int));
    printf("Enter the degree of each vertex of the graph: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&deg[i]);
    }
    int** adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
    }
    printf("Enter all the connected vertices for each vertex: ");
    for(int i=0; i<n; i++)
    {
        printf("\ni=%d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    int* stack = (int*)malloc(n*sizeof(int));
    int top = 0;
    bool* visited = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    int src, dest;
    printf("Enter source and destination: ");
    scanf("%d %d",&src,&dest);
    printf("The path is(that is, if it exists at all): ");
    path(adj, deg, n, src, dest, visited, stack, top);
    return 0;
}