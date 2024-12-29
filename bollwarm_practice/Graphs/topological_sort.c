#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Froggy remember a few extra brackets are not going to hurt anybody

void topologicalSortUtil(int** adj, int* deg, int n, int v, bool* visited, int* stack, int* top)
{
    visited[v] = true;
    for(int i=0; i<deg[v]; i++)
    {
        if(!visited[adj[v][i]])
        {
            topologicalSortUtil(adj, deg, n, adj[v][i], visited, stack, top);
        }
    }
    stack[(*top)++] = v;
    //printf("\nhi!v=%d, top=%d",v,*top);  
    /*for(int i=0; i<*top; i++)
    {
        printf("%d ",top);
    }
    printf("\n");*/
}

void topologicalSort(int** adj, int* deg, int n)
{
    int* stack = (int*)malloc(n*sizeof(int));
    bool* visited = (bool*)malloc(n*sizeof(bool));
    int top = 0;
    //printing the garbage values in the stack - and what's more the crappy values aren't getting changed
    /*for(int i=0; i<n; i++)
    {
        printf("%d ",stack[i]);
    }*/
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            topologicalSortUtil(adj, deg, n, i, visited, stack, &top);
        }
    }
    //this is wrong because I printed it from the front, it should've be the way round
    for(int i=n-1; i>=0; i--)
    {
        printf("%d ",stack[i]);
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d",&n);
    int* deg = (int*)malloc(n*sizeof(int));
    printf("Enter the degree of each node in the graph: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&deg[i]);
    }
    printf("Enter all the connected vertices of each of the vertices: ");
    int** adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
    }
    for(int i=0; i<n; i++)
    {
        printf("\ni=%d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    //printing the adjacency matrix just in case
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<deg[i]; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
    topologicalSort(adj, deg, n);
    return 0;
}
