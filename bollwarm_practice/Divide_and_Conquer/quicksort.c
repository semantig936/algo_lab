#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int pInd = low;
    for(int i=low; i<=high; i++)
    {
        if(arr[i]<pivot)
        {
            swap(&arr[pInd],&arr[i]);
            pInd++;
        }
    }
    swap(&arr[pInd],&arr[high]);
    return pInd;
}

void quicksort(int* arr, int low, int high)
{
    // base case
    if(high < low)
    {
        return;
    }
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
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
    quicksort(arr, 0, n-1);
    printf("\nThe array in sorted order is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}