#include<stdio.h>
#include<stdlib.h>

void floyd_warshal(int** dist, int n)
{
    for(int k=0; k<n;k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Distance matrix");
    for(int i=0; i<n; i++)
    {
        printf("\n");
        for(int j=0; j<n; j++)
        {
            if(dist[i][j] >= 100)
            {
                printf("INF ");
            }
            else
            {
                printf("%d ",dist[i][j]);
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter the elements of the adjacency matrix: ");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    floyd_warshal(adj, n);
    return 0;
}