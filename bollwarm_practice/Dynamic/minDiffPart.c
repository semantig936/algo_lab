#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int minDiff(int* arr, int n, int S1, int S2)
{
    printf("\nEntered the minDiff function, n=%d",n);
    //Base case
    if(n < 0)
    {
        return abs(S1-S2);
    }
    int incl = minDiff(arr, n-1, S1+arr[n], S2);
    int excl = minDiff(arr, n-1, S1, S2+arr[n]);
    printf("\nincl = %d, excl = %d",incl,excl);
    if(incl > excl)
    {
        return excl;
    }
    else
    {
        return incl;
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
    int S1 = 0;
    int S2 = 0;
    int min_difference = minDiff(arr, n, S1, S2);  
    printf("\nMinimum difference is: %d",min_difference);
    return 0;
}