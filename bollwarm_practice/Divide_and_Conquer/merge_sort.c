#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int* aux, int low, int mid, int high)
{
    int i = low; 
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        aux[k++] = arr[i++];
    }
    while(j <= high)
    {
        aux[k++] = arr[j++];
    }
    for(int x=low; x<=high; x++)
    {
        //printf("%d ",aux[x]);
        arr[x] = aux[x];
    }
    //printf("\n");
}

void mergesort(int* arr, int* aux, int low, int high)
{
    if(high <= low)
    {
        return;
    }
    int mid = (low+high)/2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid+1, high);
    merge(arr, aux, low, mid, high);
}

int main()
{
    int n;
    printf("\nEnter the value of n: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int* aux = (int*)malloc(n*sizeof(int));
    mergesort(arr, aux, 0, n-1);
    printf("\nThe array after sorting: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",aux[i]);
    }
    return 0;
}