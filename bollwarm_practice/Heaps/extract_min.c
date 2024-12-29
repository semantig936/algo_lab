#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printHeap(int* arr, int n)
{
    printf("\nHeap is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void heapify(int* arr, int n, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[smallest]>arr[l])
    {
        smallest = l;
    }
    if(r<n && arr[smallest]>arr[r])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(&arr[smallest], &arr[i]);
        heapify(arr, n, smallest);
    }
    //printHeap(arr, n);
}

void createHeap(int* arr, int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    printHeap(arr, n);
}

int main()
{
    int n;
    printf("Enter the number of elements in the heap: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the heap array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    createHeap(arr, n);
}