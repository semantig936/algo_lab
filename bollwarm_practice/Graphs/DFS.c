#include<stdio.h>
#include<stdlib.h>

void DFSutil(int** adj, int* deg, int* visit, int v)
{
    printf("%d ",v);
    visit[v] = 1;
    for(int i=0; i<deg[v]; i++)
    {
        if(visit[adj[v][i]]==0)
        {
            DFSutil(adj, deg, visit, adj[v][i]);
        }
    }
}

void DFS(int** adj, int* deg, int n)
{
    int* visit = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        visit[i] = 0;
    }
    DFSutil(adj, deg, visit, 0);
}

int main()
{
    int n, e;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the number of edges: ");
    scanf("%d",&e);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* temp = (int*)malloc(n*sizeof(int));
    printf("Vertex names are being displayed. Enter the connected nodes one by one. Enter -1 to denote that it's the end");
    for(int i=0; i<n; i++)
    {
        printf("\ni=%d: ",i);
        int tp = 0;
        do
        {
            scanf("%d",&temp[tp]);
            tp++;
        }
        while(temp[tp-1]!=-1);
        tp--;
        deg[i] = tp;
        adj[i] = (int*)malloc((deg[i]+1)*sizeof(int));
        for(int j=0; j<deg[i]; j++)
        {
            adj[i][j] = temp[j];
        }
    }
    printf("\nPrinting all the vertices in DFS order: ");
    DFS(adj, deg, n);
    return 0;
}