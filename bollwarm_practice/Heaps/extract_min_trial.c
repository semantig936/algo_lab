#include<stdio.h>
#include<stdlib.h>

struct heap
{
    int* arr;
    int size;
    int capacity;
};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void printHeap(struct heap* h)
{
    for(int i=0; i<h->size; i++)
    {
        printf("%d ",h->arr[i]);
    }
}

void heapify(struct heap* h, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<h->size && h->arr[l]<h->arr[smallest])
    {
        smallest = l;
    }
    if(r<h->size && h->arr[r]<h->arr[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

int removeMin(struct heap* h)
{
    int min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size = h->size - 1;
    heapify(h, 0);
    return min;
}

struct heap* createHeap(int* arr, int n)
{
    struct heap * h = (struct heap*)malloc(sizeof(struct heap*));
    h->size = n;
    h->arr = arr;
    for(int i=(h->size)/2-1; i>=0; i--)
    {
        heapify(h, i);
    }
    return h;
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements in the heap: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nHeap created is: ");
    struct heap* h = createHeap(arr, n);
    printHeap(h);
    int m = removeMin(h);
    printf("\nThe minimum element in the heap is: %d",m);
    printf("\nAfter extracting the minimum element, the heap is: ");
    printHeap(h);
    return 0;
}