#include<stdio.h>
#include<stdlib.h>

struct heap
{
    int n;
    int* arr;
};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct heap* h, int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if(l<h->n && h->arr[l]<h->arr[smallest])
    {
        smallest = l;
    }
    if(r<h->n && h->arr[r]<h->arr[smallest])
    {
        smallest = r;
    }
    if(smallest!=i)
    {
        swap(&h->arr[smallest], &h->arr[i]);
        heapify(h, smallest);
    }
}

struct heap* createMinHeap(int* arr, int n)
{
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->n = n;
    h->arr = arr;
    for(int i=(h->n)/2-1; i>=0; i--)
    {
        heapify(h, i);
    }
    return h;
}

int removeMin(struct heap* h)
{
    int temp = h->arr[0];
    h->arr[0] = h->arr[h->n-1];
    h->n--;
    heapify(h, 0);
    return temp;
}

void insert(struct heap* h, int val)
{
    h->n++;
    int i = h->n-1;
    while(i>0 && val<h->arr[(i-1)/2])
    {
        h->arr[i] = h->arr[(i-1)/2];
        i = (i-1)/2;
    }
    h->arr[i] = val;
}

int minCost(struct heap* h)
{
    int cost = 0;
    while(h->n > 1)
    {
        int smallest = removeMin(h);
        int sec_smallest = removeMin(h);
        cost = cost + smallest + sec_smallest;
        insert(h, smallest+sec_smallest);
    }
    return cost;
}

int main()
{
    int n;
    printf("Enter the number of ropes you have: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the size of the ropes: ");;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    struct heap* h = createMinHeap(arr, n);
    int cost = minCost(h);
    printf("Minimum cost is: %d",cost);
    return 0;
}