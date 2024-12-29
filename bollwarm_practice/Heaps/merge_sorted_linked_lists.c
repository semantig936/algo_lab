#include<stdio.h>
#include<stdlib.h>

//I'll write this code for k sorted arrays and then maybe extend it to linked lists later on

struct link
{
    int data;
    struct node* next;
};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* arr, int n, int i)
{
    int smallest = arr[i];
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<n && arr[l]<arr[smallest])
    {
        smallest = arr[l];
    }
    if(r<n && arr[r]<arr[smallest])
    {
        smallest = arr[r];
    }
    if(i!=smallest)
    {
        swap(&arr[i],&arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int* arr, int n)
{
    
}

int main()
{
    int k;
    printf("Enter the number of arrays: ");
    scanf("%d",&k);
    printf("Enter the number of elements in each of the k sorted arrays: ");
    int* ele = (int*)malloc(k*sizeof(int));
    for(int i=0; i<k; i++)
    {
        scanf("%d",&ele[i]);
    }
    
}