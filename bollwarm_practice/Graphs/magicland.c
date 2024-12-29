#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct _node
{
    int vno;
    struct _node* next;
}node;

typedef struct _vertex
{
    node* adjlist;
}vertex;

void DFSVisit(int** adj, int* deg, int rem, int v, bool* visited)
{
    visited[v] = true;
    for(int i=0; i<deg[v]; i++)
    {
        if(adj[v][i] != rem)
        {
            if(!visited[adj[v][i]])
            {
                DFSVisit(adj, deg, rem, visited);
            }
        }
    }
}

int compDFS(int** adj, int* deg, int n, int rem, bool* visited)
{
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(i != rem)
        {
            if(!visited[i])
            {

            }
        }
    }
}

void findCritical(int** adj, int* deg, int n)
{
    bool* visited = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {

    }
}

int main()
{
    int n, e;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d",&n,&e);
    //I'll once do it using the adjacency list format I know
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    printf("Enter the neighbours of each of the vertices: ");
    for(int i=0; i<n; i++)
    {
        printf("\nDegree of Vertex %d: ",i);
        scanf("%d",&deg[i]);
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
        printf("Neighbours of %d: ", i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("\nAdjacency list of the graph: ");
    for(int i=0; i<n; i++)
    {
        printf("\nVertex %d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            printf("%d ",adj[i][j]);
        }
    }
    findCritical(adj, deg, n);
    return 0;
}