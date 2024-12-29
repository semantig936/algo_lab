#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

void printArray(int* arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[largest]<arr[l])
    {
        largest = l;
    }
    if(r<n && arr[largest]<arr[r])
    {
        largest = r;
    }
    if(i!=largest)
    {
        swap(&arr[largest],&arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    for(int i=n-1; i>=0; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int  n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr, n);
    printf("\nAfter sorting, the array: ");
    printArray(arr, n);
    return 0;
}