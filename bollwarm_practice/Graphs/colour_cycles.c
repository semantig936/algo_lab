#include<stdio.h>
#include<stdlib.h>

void DFS(int** adj, int* deg, int* colour, int* visited, int v)
{
    visited[v] = 1;
}

void addEdge(int** adj, int* deg, int u, int v)
{
    adj[u][deg[u]] = v;
    adj[v][deg[v]] = u;
    deg[u]++;
    deg[v]++;
}

void readGraph(int** adj, int* deg, int* colour)
{
    int u, v;
    printf("Keep entering the edges(enter -1 when you're done)");
    do
    {
        printf("\nu=");
        scanf("%d",&u);
        printf("v=");
        scanf("%d",&v);
        addEdge(adj, deg, u, v);
    }
    while (u!=-1);   
}

void prnGraph(int** adj, int*deg, int* colour, int n)
{
    for(int i=0; i<n; i++)
    {
        if(colour[i])
        {
            printf("[b]");
        }
        else
        {
            printf("[r]");
        }
        printf("%d ->",i);
        for(int j=0; j<deg[i]; j++)
        {
            printf("%d ", adj[i][j]);
        }

    }
}

int main()
{
    int n;
    printf("Enter the number of edges: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* colour = (int*)malloc(n*sizeof(int));
    printf("Enter the colours of the matrices, ie, 0 for red and 1 for blue: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&colour[i]);
    }
    //I'm keeping adj as a n*n matrix, just to be on the safe side
    for(int i=0; i<n; i++)
    {
        deg[i] = 0;
    }
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(n*sizeof(int));
    }
    int* visited = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        visited[i] = 0;
    }
}