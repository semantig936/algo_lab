#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i)
{
    int parent = (i-1)/2;
    if(arr[parent] > arr[i])
    {
        swap(&arr[parent], &arr[i]);
        heapify(arr, n, parent);
    }
}

void createMinHeap(int* arr, int n)
{
    for(int i=n/2-1; i<n; i++)
    {
        heapify(arr, n, i);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements in the max heap: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    createMinHeap(arr, n);
    printf("The min heap created is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}