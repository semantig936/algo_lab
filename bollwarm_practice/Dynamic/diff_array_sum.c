#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void printSoln(int* x, int* y, int n, bool* i, bool* j)
{
    printf("\nArray A: ");
    for(int k=0; k<n; k++)
    {
        if(i[k])
        {
            printf("%d ",x[k]);
        }
        else
        {
            printf("  ");
        }
    }
    printf("\nArray B: ");
    for(int k=0; k<n; k++)
    {
        if(j[k])
        {
            printf("%d ",y[k]);
        }
        else
        {
            printf("  ");
        }
    }
}

int solutionExists(int* a, int* b, int ind, int n, int t, bool* i, bool* j)
{
    if(ind>=n)
    {
        return 0;
    }
    if(t==0 && ind==n-1)
    {
        return 1;
    }
    //return solutionExists(a, b, ind+1, n, t-a[ind], i, j) + solutionExists(a, b, ind+1, n, t-b[ind], i, j);
    if(solutionExists(a, b, ind+1, n, t-a[ind], i, j))
    {
        i[ind] = true;
    }
    else if(solutionExists(a, b, ind+1, n, t-b[ind], i, j))
    {
        j[ind] = true;
    }
    else
    {
        return 0;
    }
    return solutionExists(a, b, ind+1, n, t-a[ind], i, j) + solutionExists(a, b, ind+1, n, t-b[ind], i, j);
}

int main()
{
    int n;
    printf("Enter the number of elements in each array: ");
    scanf("%d",&n);
    int* a = (int*)malloc(n*sizeof(int));
    int* b = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of array A: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the elements of array B: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&b[i]);
    }
    int t;
    printf("Enter the value of t: ");
    scanf("%d",&t);
    bool* i = (bool*)malloc(n*sizeof(bool));
    bool* j = (bool*)malloc(n*sizeof(bool));
    for(int k=0; k<n; k++)
    {
        i[k] = false;
        j[k] = false;
    }
    if(solutionExists(a, b, 0, n, t, i, j))
    {
        printf("Solution exists.");
        printSoln(a, b, n, i, j);
    }
    else
    {
        printf("Solution doesn't exist.");
    }
    return 0;
}