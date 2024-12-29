#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//if you copy the code from online platforms and the only thing you do is translate, then the code will invariably be correct
//for all I'm concerned, pathExist doesn't get modified at all throughout the code - and there wasn't any difference whatsoever
void printAllPathsUtil(int** adj, int* deg, int n, int v1, int v2, bool pathExist, bool* visited, int* path, int index)
{
    visited[v1] = true;
    path[index++] = v1;
    if(v1==v2)
    {
        int i;
        printf("\nOne of the paths between %d and %d: ",path[0],v2);
        for(i=0; i<index-1; i++)
        {
            printf("%d->",path[i]);
        }
        printf("%d",path[index-1]);
        /*if(!pathExist)
        {
            printf("\nOne of the paths between %d and %d: ",path[0],v2);
            for(i=0; i<index-1; i++)  
            {
                printf("%d->",path[i]);
            }
            printf("%d",path[index-1]);
        }*/
    }
    else
    {
        for(int i=0; i<deg[v1]; i++)
        {
            if(!visited[adj[v1][i]])
            {
                printAllPathsUtil(adj, deg, n, adj[v1][i], v2, pathExist, visited, path, index);
            }
        }
    }
    visited[v1] = false;
    index--;
}

void printAllPaths(int** adj, int* deg, int n, int v1, int v2)
{
    bool* visited = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
    }
    int* path = (int*)malloc(n*sizeof(int));
    int index = 0;
    bool pathExist = false;
    printAllPathsUtil(adj, deg, n, v1, v2, pathExist, visited, path, index);
}

int main()
{
    int n;
    printf("Enter the number of nodes in your graph: ");
    scanf("%d",&n);
    int* deg = (int*)malloc(n*sizeof(int));
    printf("Enter the degree of each node: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&deg[i]);
    }
    int** adj = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
    }
    printf("Enter the values of the nodes you can access from your graph:\n");
    for(int i=0; i<n; i++)
    {
        printf("i=%d: ",i);
        for(int j=0; j<deg[i]; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    int src, dest;
    printf("Enter the source and the destination vertex: ");
    scanf("%d %d",&src,&dest);
    printAllPaths(adj, deg, n, src, dest);

}