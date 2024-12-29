#include<stdio.h>
#include<stdlib.h>

void print_result(int* arr, int n, int i, int x)
{
    if(i >= n)
    {
        return;
    }
    if(arr[i] <= x)
    {
        printf("%d ",arr[i]);
        print_result(arr, n, 2*i+1, x);
        print_result(arr, n, 2*i+2, x);
    }
}

int main()
{
    int n;
    printf("Enter the no. of nodes in the heap: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter x: ");
    scanf("%d",&x);
    printf("Elements less than %d are: ",x);
    print_result(arr, n, 0, x);
    return 0;
}