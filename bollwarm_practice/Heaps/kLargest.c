#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int ind)
{
    int smallest = ind;
    int l = 2*ind + 1;
    int r = 2*ind + 2;
    if(l<n && arr[l]<arr[smallest])
    {
        smallest = l;
    }
    if(r<n && arr[r]<arr[smallest])
    {
        smallest = r;
    }
    if(ind != smallest)
    {
        swap(&arr[smallest], &arr[ind]);
        heapify(arr, n, smallest);
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
    int n;
    printf("Enter the no. of elements in the heap: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter the value of k: ");
    scanf("%d",&k);
    heapSort(arr, n);
    printf("\nThe kth largest element is: %d",arr[k-1]);
    return 0;
}