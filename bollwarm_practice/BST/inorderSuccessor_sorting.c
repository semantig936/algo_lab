#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int* aux, int low, int mid, int high)
{
    //printf("\nEntered merge with low=%d, high=%d and mid=%d",low, high, mid);
    int i=low, j=mid+1, k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
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
    while(j<=high)
    {
        aux[k++] = arr[j++];
    }
    /*printf("\nThe current situation of the auxillary array  is: ");
    for(int x=low; x<=high; x++)
    {
        printf("%d ",aux[x]);
    }*/
    for(int x=low; x<=high; x++)
    {
        arr[x] = aux[x];
    }
}

void mergesort(int* arr, int* aux, int low, int high)
{
    //printf("\nEntered mergesort");
    if(high<=low)
    {
        return;
    }
    /*printf("\nCurrent situation of the array segment: ");
    for(int i=low; i<=high; i++)
    {
        printf("%d ",arr[i]);
    }*/
    int mid = low + (high-low)/2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid+1, high);
    merge(arr, aux, low, mid, high);
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
    int* aux = (int*)malloc(n*sizeof(aux));
    mergesort(arr, aux, 0, n-1);
    int key;
    printf("\nEnter the key value: ");
    scanf("%d",&key);
    printf("\nThe successor value is: ");
    for(int i=0; i<n-1; i++)
    {
        if(key == arr[i])
        {
            printf("%d",arr[i+1]);
        }
    }
    return 0;
}