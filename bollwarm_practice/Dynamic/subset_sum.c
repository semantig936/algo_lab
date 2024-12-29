#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isSubsetSum(int* arr, int n, int sum)
{
    bool* prev = (bool*)malloc((sum+1)*sizeof(bool));
    prev[0] = true;
    for(int i=1; i<=sum; i++)
    {
        prev[i] = false;
    }
    bool* curr = (bool*)malloc((sum+1)*sizeof(bool));
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=sum; j++)
        {
            if(j<arr[i-1])
            {
                curr[j] = prev[j];
            }
            if(j>=arr[i-1])
            {
                curr[j] = prev[j] ||  prev[j-arr[i-1]];
            }
        }
        prev = curr;
    }
    return prev[sum];
}

int main()
{
    int n, sum;
    printf("Enter the nuumber of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements in the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d",&sum);
    if(isSubsetSum(arr, n, sum))
    {
        printf("Subset sum possible.");
    }
    else
    {
        printf("Subset sum not possible.");
    }
    return 0;
}