#include<stdio.h>
#include<stdlib.h>

// I'm sorting in ascending order
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
    int key, j;
    for(int i=1; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>=key)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    printf("\nThe sorted array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}