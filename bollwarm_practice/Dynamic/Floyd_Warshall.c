#include<stdio.h>
#include<stdlib.h>

// Remember that the pointers have something like a global scope so path and cost will remain fixed throughout
// We try to print the path from vertex u to vertex v
void printPath(int** path, int u, int v)
{
    printf("\nEntered printPath, u=%d, v=%d",u,v);
    if(path[u][v] == u)// full cycle or something - base case maybe
    {
        printf("%d",path[u][v]);
        return;
    }
    printf("\nBase case was false");
    printPath(path, u, path[u][v]);
    printf("%d ",u);
}

void calculateCost(int** adj, int n, int v1, int v2)
{
    printf("\nEntered calculateCost, v1=%d, v2=%d ",v1,v2);
    // Introducing the cost and the path matrices(creating memory spaces)
    int** cost = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        cost[i] = (int*)malloc(n*sizeof(int));
    }
    int** path = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        path[i] = (int*)malloc(n*sizeof(int));
    }

    // initialising the cost and the path matrices
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cost[i][j] = adj[i][j];
        }
    }
    // i is the index for the source vertex and j is for the destination vertex
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
            {
                path[i][j] = 0;
            }
            else if(adj[i][j]<10)
            {
                path[i][j] = j;
            }
            else
            {
                path[i][j] = -1;
            }
        }
    }
    // u is the source vertex and v is the destination vertex
    for(int k=0; k<n; k++)
    {
        for(int u=0; u<n; u++)
        {
            for(int v=0; v<n; v++)
            {
                if(cost[u][k] + cost[k][v] < cost[u][v])
                {
                    cost[u][v] = cost[u][k] + cost[k][v];
                    path[u][v] = path[k][v];
                }
            }
        }
    }
    printf("\nThe cost matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    printf("\nThe path matrix is:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
    printf("Calling printPath with v1=%d, v2=%d",v1,v2);
    printPath(adj, v1, v2);
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    int** g = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        g[i] = (int*)malloc(n*sizeof(int));
    }
    printf("\nEnter the elements of the adjacency matrix of the graph(for unjoined source and destination, enter a huge number): ");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    int v1, v2;
    printf("\nEnter the source and the destination vertices:");
    scanf("%d %d",&v1,&v2);
    printf("\nValues of v1 and v2 entered are: v1=%d, v2=%d\n",v1,v2);
    calculateCost(g, n, v1, v2);
    return 0;
}