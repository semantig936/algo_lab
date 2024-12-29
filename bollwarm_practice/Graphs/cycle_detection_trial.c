#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isCyclicUtil(int** adj, int* deg, int n, int v, bool* visited, bool* recstack)
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recstack[v] = true;
    }
}

bool isCyclic(int** adj, int* deg, int n)
{
    bool* visited = (bool*)malloc(n*sizeof(bool));
    bool* recstack = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {
        visited[i] = false;
        recstack[i] = false;
    }
    for(int i=0; i<n; i++)
    {
        if(!visited[i] && isCyclicUtil(adj, deg, n, i, visited, recstack))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* temp = (int*)malloc(n*sizeof(int));
    printf("Enter all the connected vertices of each given vertex(enter -1 to denote the end): ");
    for(int i=0; i<n; i++)
    {
        int tp = 0;
        printf("\n%d: ",i);
        do
        {
            scanf("%d",&temp[tp++]);
        }
        while (temp[tp-1] != -1);
        deg[i] = tp - 1;
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
        for(int j=0; j<deg[i]; j++)
        {
            adj[i][j] = temp[j];
        }
    }
}