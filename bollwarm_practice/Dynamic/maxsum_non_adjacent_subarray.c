#include<stdio.h>
#include<stdlib.h>

// for prev they've taken INT_MIN, but it's just an index, so I've decided to take -1
// -1 is actually incorrect because then the 0th element will always be excluded, so I've taken any negative value but not -1
int max_sum(int* arr, int i, int n, int prev)
{
    // Base case when the end of the array is reached
    if(i==n)
    {
        return 0;
    }
    int excl = max_sum(arr, i+1, n, prev); // completely ignoring the ith element
    int incl = 0;
    if(i!=prev+1)
    {
        incl = max_sum(arr, i+1, n, i) + arr[i]; // forcefully including the ith element checking for the remaining elements 
    }
    if(incl>excl)
    {
        return incl;
    }
    else
    {
        return excl;
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nThe maximum sum is = %d",max_sum(arr, 0, n, -2));
}