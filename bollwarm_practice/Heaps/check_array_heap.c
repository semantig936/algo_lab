#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool heapCheck(int* arr, int n)
{
    int l, r;
    for(int i=0; i<n; i++)
    {
        l = 2*i + 1;
        r = 2*i + 2;
        if(l<n)
        {
            if(arr[i] < arr[l])
            {
                return false;
            }
        }
        if(r<n)
        {
            if(arr[i] < arr[r])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    printf("Enter the number of nodes in the heap: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    if(heapCheck(arr, n))
    {
        printf("It is a max heap");
    }
    else
    {
        printf("It is not a max heap");
    }
    return 0;
}