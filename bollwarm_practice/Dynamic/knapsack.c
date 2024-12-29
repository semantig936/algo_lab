#include<stdio.h>
#include<stdlib.h>

int knapsack(int ind, int w,  int* val, int* wt, int** aux)
{
    if(ind<0)//if it doesn't work out check it putting equality
    {
        return 0;
    }
    if(aux[ind][w] != -1)
    {
        return aux[ind][w];
    }
    if(wt[ind] > w)
    {
        return knapsack(ind-1, w, val, wt, aux);
    }
    if(wt[ind] <= w)
    {
        int inc = knapsack(ind-1, w-wt[ind], val, wt, aux) + val[ind];
        int exc = knapsack(ind-1, w, val, wt, aux);
        if(inc > exc)
        {
            return inc;
        }
        else
        {
            return exc;
        }
    }
}

int main()
{
    int n, w;
    printf("Enter the number of elements available and the maximum capacity of the knapsack: ");
    scanf("%d %d",&n,&w);
    int* wt = (int*)malloc(n*sizeof(int));
    int* val = (int*)malloc(n*sizeof(int));
    printf("Enter the value of each of the elements available: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&val[i]);
    }
    printf("Enter the weight of each of the elements available: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&wt[i]);
    }
    int** aux = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        aux[i] = (int*)malloc((w+1)*sizeof(int));
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            aux[i][j] = -1;
        }
    }
    int value = knapsack(n-1, w, val, wt, aux);
    printf("Maximum value of the knapsack: %d",value);
    return 0;
}