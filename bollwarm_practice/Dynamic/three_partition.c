#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool subsetSum(int* arr, int n, int a, int b, int c)
{
    if(n<0)
    {
        return true;
    }
    bool A = false;
    if(a - arr[n] >= 0)
    {
        A = subsetSum(arr, n-1, a-arr[n], b, c);
    }
    bool B = false;
    if(b - arr[n] >= 0)
    {
        B = subsetSum(arr, n-1, a, b-arr[n], c);
    }
    bool C = false;
    if(c - arr[n] >= 0)
    {
        C = subsetSum(arr, n-1, a, b, c-arr[n]);
    }
    return A||B||C;
}

bool partition(int* arr, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }
    if(sum%3 != 0)
    {
        return false;
    }
    int part = sum/3;
    return subsetSum(arr, n-1, part, part, part);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    if(partition(arr, n))
    {
        printf("\nSuch a partition is possible.");
    }
    else
    {
        printf("\nSuch a partition is not possible.");
    }
    return 0;
}