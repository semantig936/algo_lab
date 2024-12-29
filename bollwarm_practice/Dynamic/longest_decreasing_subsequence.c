#include<stdio.h>
#include<stdlib.h>

void printLCS(int* x, int* y, int m, int n, int** lookup)
{
    if(m==0 || n==0)
    {
        return;
    }
    if(x[m-1] == y[n-1])
    {
        printf("\nFound one common element. x[%d-1] = %d",m, x[m-1]);
        printLCS(x, y, m-1, n-1, lookup);
        printf("%d ",x[m-1]);
        return;
    }
    if(lookup[m-1][n] > lookup[m][n-1])
    {
        printLCS(x, y, m-1, n, lookup);
    }
    else
    {
        printLCS(x, y, m, n-1, lookup);
    }
    
}

void findLCS(int* x, int* y, int n)
{
    int** lookup = (int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<=n; i++)
    {
        lookup[i] = (int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0; i<=n; i++)
    {
        lookup[i][0] = 0;
        lookup[0][i] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                lookup[i][j] = lookup[i-1][j-1] + 1;
            }
            else
            {
                if(lookup[i-1][j] > lookup[i][j-1])
                {
                    lookup[i][j] = lookup[i-1][j];
                }
                else
                {
                    lookup[i][j] = lookup[i][j-1];
                }
            }
        }
    }
    printLCS(x, y, n, n, lookup);
}

void merge(int* arr, int* aux, int low, int mid, int high)
{
    int i = low; 
    int j = mid + 1;
    int k = low;
    while(i <= mid && j <= high)
    {
        if(arr[i] >= arr[j])
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

void print_max_decreasing_subsequence(int* x, int n)
{
    /*printf("The entered array x is: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",x[i]);
    }*/
    // I'm assuming that x has all distinct elements
    int* y = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        y[i] = x[i];
    }
    int* aux = (int*)malloc(n*sizeof(int));
    mergesort(y, aux, 0, n-1);
    /*printf("\nThe elements of array y(array x after sorting) are: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",y[i]);
    }*/
    findLCS(x, y, n);
}

int main()
{
    int m; //no. of elements in array x
    printf("Enter the number of elements in the array x: ");
    scanf("%d",&m);
    int* x = (int*)malloc(m*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<m; i++)
    {
        scanf("%d",&x[i]);
    }
    printf("\nThe longest decreasing subsequence is: ");
    print_max_decreasing_subsequence(x, m);
    return 0; 
}