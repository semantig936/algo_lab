#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isCyclicUtil(int** adj, int* deg, int n, int v,  bool* visited, int parent)
{
    visited[v] = true;
    for(int i=0; i<deg[v]; i++)
    {
        if(!visited[adj[v][i]])
        {
            if(isCyclicUtil(adj, deg, n, adj[v][i], visited, v))
            return true;
        }
        else if(adj[v][i] != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCyclic(int** adj, int* deg, int n)
{
    bool* visited = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            if(isCyclicUtil(adj, deg, n, i, visited, -1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    printf("Enter the number of nodes in the graph: ");
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
    printf("Enter the vertices directly connected to each given vertex: ");
    for(int i=0; i<n; i++)
    {
        printf("\ni=%d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    if(isCyclic(adj, deg, n))
    {
        printf("Cycle exists.");
    }
    else
    {
        printf("Cycle doesn't exist.");
    }
    return 0;
}