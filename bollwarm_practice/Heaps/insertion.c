#include<stdio.h>
#include<stdlib.h>

// apparently the heapify function itself will be different for deletion and insertion function
swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int ind)
{
    int parent = (ind-1)/2;
    if(parent >= 0)
    {
        if(arr[ind] > parent)
        {
            swap(&arr[ind], arr[parent]);
            heapify(arr, n, parent);
        }
    }
}

void createMaxHeap(int* arr, int n)
{
    int start = n/2;
    for(int i=(n/2)+1; i>=0; i--)
    {
        heapify(arr, n, i);
    }
}

void insert(int* arr, int n, int k)
{

}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    //creating additional space to insert additional elements
    int* arr = (int*)malloc(2*n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
}