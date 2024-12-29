#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    return b;
}

//i indicates the start index and j indicates the end index - available to a particular user at that iteration
//n indicated the number of pots of gold left
int maxValue(int* arr, int n, int i, int j)
{
    if(n==1)
    {
        return arr[i];
    }
    if(n==2)
    {
        if(arr[i] > arr[j])
        {
            return arr[i];
        }
        else
        {
            return arr[j];
        }
    }
    int start = arr[i] + min(maxValue(arr, n-2, i+2, j), maxValue(arr, n-2, i+1, j-1));
    int end = arr[j] + min(maxValue(arr, n-2, i, j-2), maxValue(arr, n-2, i+1, j-1));
    return max(start, end);
}

int main()
{
    int n;
    printf("Enter the number of pots of gold at the beginning of the game: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the number of gold coins in each pot: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int m = maxValue(arr, n, 0, n-1);
    printf("\nThe maximum number of gold coins possible are: %d",m);
    return 0;
}