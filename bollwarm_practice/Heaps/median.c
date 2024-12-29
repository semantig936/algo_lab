#include<stdio.h>
#include<stdlib.h>

//I'll write the code yet again since it seems like I've forgotten the basic functionalities

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

void minHeapify(struct heap* h, int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if(l<h->n && h->arr[l]<h->arr[i])
    {
        smallest = l;
    }
    if(r<h->n && h->arr[r]<h->arr[smallest])
    {
        smallest = r;
    }
    if(smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        minHeapify(h, smallest);
    }
}

void maxHeapify(struct heap* h, int i)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l<h->n && h->arr[l]>h->arr[largest])
    {
        largest = l;
    }
    if(r<h->n && h->arr[r]>h->arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(&h->arr[i], &h->arr[largest]);
        minHeapify(h, largest);
    }
}

void createMinHeap(int n, int* arr)
{
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->n = n;
    h->arr = arr;
    for(int i=h->n/2-1; i<h->n; i++)
    {
        minHeapify(h, i);
    }
}

void createMaxHeap(int n, int* arr)
{
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->n = n;
    h->arr = arr;
    for(int i=h->n/2-1; i<h->n; i++)
    {
        maxHeapify(h, i);
    }
}

int removeMax(struct heap* h)
{
    int top = h->arr[0];
    h->arr[0] = h->arr[h->n-1];
    h->n--;
    maxHeapify(h, 0);
    return top;
}

int removeMin(struct heap* h)
{
    int top = h->arr[0];
    h->arr[0] = h->arr[h->n-1];
    h->n--;
    minHeapify(h, 0);
    return top;
}


void insertMin(struct heap* h, int key)
{
    h->n++;
    int i = h->n - 1;
    while(i>0 && key<h->arr[(i-1)/2])
    {
        h->arr[i] = h->arr[(i-1)/2];
        i = (i-1)/2;
    }
    h->arr[i] = key;
}

void insertMax(struct heap* h, int key)
{
    h->n++;
    int i = h->n - 1;
    while(i>0 && key>h->arr[(i-1)/2])
    {
        h->arr[i] = h->arr[(i-1)/2];
        i = (i-1)/2;
    }
    h->arr[i] = key;
}

int main()
{
    struct heap* h1 = (struct heap*)malloc(sizeof(struct heap)); //minheap comprising the larger half of the elements
    struct heap* h2 = (struct heap*)malloc(sizeof(struct heap)); //maxheap comprising the smaller half of the elements
    h1->n = 0;
    h2->n = 0;
    h1->arr = NULL;
    h1->arr = NULL;
    int x;
    int median;
    printf("Start entering numbers. Enter -1 to exit.");
    do
    {
       scanf("%d",&x);
       if(h1->n==0 && h2->n==0)
       {
        insertMin(h1, x);  
       }
       if(h1->n==0 && h2->n>0)
       {
        insertMin(h1, x);
       }
       if(h1->n>0 && h2->n==0)
       {
        insertMin(h2, x);
       }
       if(h1->n>0 && h2->n>0)
       {
        if(x>=h1->arr[0])
        {
            insertMin(h1, x);
        }
        if(x<=h2->arr[0])
        {
            insertMax(h2, x);
        }
       }
       if(h2->n - h1->n == 2)
       {
        int top = removeMax(h2);
        insertMin(h1, x);
       }
       if(h1->n - h1->n == 2)
       {
        int top = removeMin(h1);
        insertMax(h2, x);
       }
       median = h2->arr[0];
       printf("\nMedian=%d",median);
    } 
    while(x!=-1);
    
}