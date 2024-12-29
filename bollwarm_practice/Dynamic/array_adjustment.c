#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// over here, they apply some sort of big M method, and thye've defined the M to be 100
#define m 100

int minAdjustmentCost(int* arr, int target, int n)
{
    // base case
    if(n==0)
    {
        return 0;
    }
    int** T = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        T[i] = (int*)malloc((m+1)*sizeof(int));
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if()
            {}
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nPopulate the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    printf("\nEnter the minimum difference between any two consecutive elements: ");
    scanf("%d",&k);
}
