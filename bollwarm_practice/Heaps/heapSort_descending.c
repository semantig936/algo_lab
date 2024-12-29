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
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l]<arr[smallest])
    {
        smallest = l;
    }
    if(r<n && arr[r]<arr[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(&arr[i],&arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int* arr, int n)
{
    //creating a min heap for heapsorting in descending order
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
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr, n);
    printf("Sorted array is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}