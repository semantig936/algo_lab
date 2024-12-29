#include<stdio.h>
#include<stdlib.h>

//using pointers to make the change permanent
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ind is the index of the root
void heapify(int* arr, int n, int ind)
{
    int largest = ind;
    int l = 2*ind + 1;
    int r = 2*ind + 2;
    if(l<n && arr[largest]<arr[l])
    {
        largest = l;
    }
    if(r<n && arr[largest]<arr[r])
    {
        largest = r;
    }
    if(largest != ind)
    {
        swap(&arr[ind], &arr[largest]);
        heapify(arr, n, largest);
    }  
}

void printHeap(int* arr, int n)
{
    printf("\nThe final heap is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void createMaxHeap(int* arr, int n)
{
    int start = (n/2) - 1;
    for(int i=start; i>=0; i--)
    {
        heapify(arr, n, i);
    }  
    printHeap(arr, n);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements in the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    createMaxHeap(arr, n);
    return 0;
}