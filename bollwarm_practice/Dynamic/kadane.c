#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int kadane(int n, int* arr)
{
    int max_ending_here = 0;
    int sum = -1000;
    for(int i=0; i<n; i++)
    {
        max_ending_here = max(max_ending_here + arr[i], arr[i]);
        if(max_ending_here > sum)
        {
            sum = max_ending_here;
        }
    }
    printf("The desired largest subsequence sum is: %d",sum);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements in the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    kadane(n, arr);
    return 0;
}