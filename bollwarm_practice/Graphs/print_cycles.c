#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* temp = (int*)malloc(n*sizeof(int));
    printf("Reading graph...");
    for(int i=0; i<n; i++)
    {
        printf("\n%d ",i);
        int tp = 0;
        do
        {
            scanf("%d",&temp[tp]);
        }
        while (temp[tp-1]!=-1);
        deg[i] = tp - 1;
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
        for(int j=0; j<deg[i]; j++)
        {
            adj[i][j] = temp[j];
        }
    }
    int** cycles = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        cycles[i] = (int*)malloc(n*sizeof(int));
    }
    int c = 0; //to keep the count of the number of cycles
    int* ind = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        ind[i] = 0;
    }
    int* colour = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        colour[i] = 0;
    }
}
