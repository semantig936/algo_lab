#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int source;
    int dest;
    int weight;
} edge;

void printPath(int* parent, int vertex, int source)
{
    if(vertex<0)
    {
        return;
    }
    printPath(parent, parent[vertex], source);
    if(vertex!=source)
    {
        printf("->");
    }
    printf("%d",vertex);
}

void distanceParent(edge* arr, int n, int source)
{
    int* parent = (int*)malloc(n*sizeof(int));
    int* distance = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
    }
    int u, v, w;
    for(int i=0; i<n; i++)
    {
        u = arr[i].source;
        v = arr[i].dest;
        w = arr[i].weight;
        if(distance[u] != INT_MIN && distance[u]+w < distance[v])
        {
            distance[v] = distance[u] + w;
            parent[v] = u;
        }
    }
    for(int i=0; i<n; i++)
    {
        printf("Distance of vertex %d from the source is: ",distance[i]);
        printf("\nPath is: ");
        printPath(parent, i, source);
    }
}

int main()
{
    int n;
    printf("Enter the number of edges in the graph: ");
    scanf("%d",&n);
    edge* arr = (edge*)malloc(n*sizeof(edge));
    int v;
    printf("\nEnter the number of vertices in the graph: ");
    scanf("%d",&v);
    printf("\nEnter the edges of the graph: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d",&arr[0].source,&arr[0].dest,&arr[0].weight);
    }
    printf("\nSuccessfully taken the input of the edges...");
    int s;
    printf("\nEnter the source vector: ");
    scanf("%d",&s);
    distanceParent(arr, v, s);
}