#include<stdio.h>
#include<stdlib.h>

struct heap
{
    int* arr;
    int n;
};

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct heap* h, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l<h->n && h->arr[l]<h->arr[smallest])
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
        heapify(h, smallest);
    }
}

struct heap* createMinHeap(int* arr, int n)
{
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    h->arr = arr;
    h->n = n;
    for(int i=h->n/2-1; i>=0; i--)
    {
        heapify(h, i);
    }
    return h;
}

int findMin(struct heap* h)
{
    int m = h->arr[0];
    h->arr[0] = h->arr[h->n-1];
    h->n--;
    heapify(h, 0);
    return m;
}

int main()
{
    int n1, n2, k;
    printf("Enter the number of elements in each of the two heaps: ");
    scanf("%d %d",&n1,&n2);
    int* arr1 = (int*)malloc(n1*sizeof(int));
    int* arr2 = (int*)malloc(n2*sizeof(int));
    printf("Enter the elements of the first array: ");
    for(int i=0; i<n1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter the elements of the second array: ");
    for(int i=0; i<n2; i++)
    {
        scanf("%d",&arr2[i]);
    }
    struct heap* h1 = createMinHeap(arr1, n1);
    struct heap* h2 = createMinHeap(arr2, n2);
    printf("Enter the number pf minimum sums you want: ");
    scanf("%d",&k);
    for(int i=0; i<k; i++)
    {
        //printing the heaps just for the sake of it
        /*printf("\nArray in heap1: ");
        for(int i=0; i<h1->n; i++)
        {
            printf("%d ",h1->arr[i]);
        }
        printf("\nArray in heap2: ");
        for(int i=0; i<h2->n; i++)
        {
            printf("%d",h2->arr[i]);
        }*/
        int m1 = findMin(h1);
        int m2 = findMin(h2);
        int sum = m1 + m2;
        printf("\n[%d, %d], sum = %d",m1,m2,sum);
    }
    return 0;
}