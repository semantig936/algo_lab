#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void hamiltonian(int n, int** adj, int* deg)
{
    int* path = (int*)malloc(n*sizeof(int));
    int ind = 0;
    path[0] = 0;
    ind++;
    bool* added = (bool*)malloc(n*sizeof(bool));
    for(int i=0; i<n; i++)
    {
        added[i] = false;
    }
    while(path[ind-1]!=0)
    {

    } 
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    int** adj = (int**)malloc(n*sizeof(int*));
    int* deg = (int*)malloc(n*sizeof(int));
    int* temp = (int*)malloc(n*sizeof(int));
    printf("Reading graph..."); 
    for(int i=0; i<n; i++)
    {
        printf("\n%d: ",i);
        int tp = 0;
        do
        {
            scanf("%d",&temp[tp]);
            tp++;
        }
        while (temp[tp-1]!=-1);
        deg[i] = tp - 1;
        adj[i] = (int*)malloc(deg[i]*sizeof(int));
        for(int j=0; j<deg[i]; j++)
        {
            adj[i][j] = temp[j];
        }
    }
    int* path = (int*)malloc(n*sizeof(int));
}