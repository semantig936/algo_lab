#include<stdio.h>
#include<stdlib.h>

int countWays(int* arr, int n, int target)
{
    // How on earth am I getting negative targets?! Okay - that part is fine.
    printf("\ntarget=%d",target);
    if(target==0)
    {
        return 1;
    }
    if(target<0)
    {
        return 0;
    }
    //printf("\nReached this part...");
    int result = 0;
    for(int i=0; i<n; i++)
    {
        result+= countWays(arr, n, target-arr[i]); //Well at least this part was nothing unexpected
        printf("\nresult=%d",result);
    }
    return result;
}

int main()
{
    int n;
    printf("Enter the number of different denominations of coins there are: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the different denominations of coins you have: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int target;
    printf("\nEnter the target amount you want: ");
    scanf("%d",&target);
    int ways = countWays(arr, n, target);
    printf("\nThe total number of ways is: %d",ways);
    return 0;
}