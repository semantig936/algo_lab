#include<stdio.h>
#include<stdlib.h>
// I'm gonna make a max heap and then find the max and min and then remove the max and min

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
    if(ind != largest)
    {
        swap(&arr[ind], &arr[largest]);
        heapify(arr, n, largest);
    }
}

//finding it in O(n) time is okay enough but we have to do it in O(logn)
int minElement(int* arr, int n)
{
    int min = arr[n/2];
    for(int i=(n/2)+1; i<n; i++)
    {
        if(min > arr[n-1])
        {
            min = arr[n-1];
        }
    }
    return min;
}

void createMaxHeap(int* arr, int n)
{
    int start = (n/2) + 1;
    for(int i=start; i>=0; i--)
    {
        heapify(arr, n, i);
    }
    printf("\nThe max heap is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nThe largest element is: %d",arr[0]);
    printf("\nThe minimum element is: %d",minElement(arr, n));
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
    createMaxHeap(arr, n);
}