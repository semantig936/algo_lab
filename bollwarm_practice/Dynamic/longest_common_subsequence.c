#include<stdio.h>
#include<stdlib.h>

void print_LCS(int* x, int* y, int m, int n, int** lookup)
{
    if(m==0 || n==0)
    {
        return;
    }
    if(x[m-1] == y[n-1])
    {
        print_LCS(x, y, m-1, n-1, lookup);
        printf("%d ",x[m-1]);
    }
    else
    {
        if(lookup[m-1][n] > lookup[m][n-1])
        {
            print_LCS(x, y, m-1, n, lookup);
        }
        else
        {
            print_LCS(x, y, m, n-1, lookup);
        }
    }
}

// m is the number of elements in a and n is the number of elements in b
void findLCS(int* a, int* b, int m, int n)
{
    //lookup will be a (m+1)*(n+1) matrix with the entire first row and the entire first column 0
    int** lookup = (int**)malloc((m+1)*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        lookup[i] = (int*)malloc((n+1)*sizeof(int));
    }
    for(int j=0; j<n; j++)
    {
        lookup[0][j] = 0;
    }
    for(int i=0; i<m; i++)
    {
        lookup[i][0] = 0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i-1] == b[j-1])
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
    print_LCS(a, b, m, n, lookup); 
}

void merge(int* arr, int* aux, int low, int mid, int high)
{
    int i=low, j=mid+1, k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]>arr[j])
        {
            aux[k++] = arr[j++];
        }
        else
        {
            aux[k++] = arr[i++];
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
    for(int x=low; x<=high; x++)
    {
        arr[x] = aux[x];
    }
}

void mergesort(int* arr, int* aux, int low, int high)
{
    if(high<=low)
    {
        return;
    }
    int mid = low + (high-low)/2;
    mergesort(arr, aux, low, mid);
    mergesort(arr, aux, mid+1, high);
    merge(arr, aux, low, mid, high);
}

int removeDuplicates(int* arr, int n)
{
    int* newarr = (int*)malloc(n*sizeof(int));
    int prev = arr[0];
    int k = 1; //for the index of the new array(one without any duplicates)
    newarr[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        if(arr[i]!=prev)
        {
            newarr[k++] = arr[i];
            prev = arr[i]; 
        }
    }
    for(int i=0; i<k; i++)
    {
        arr[i] = newarr[i];
    }
    return k;
}

int main()
{
    int n;
    printf("No of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("\nEnter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    // Creating a copy of the array arr in 'c'
    int* c = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        c[i] = arr[i];
    }
    int* aux = (int*)malloc(n*sizeof(int));
    mergesort(c, aux, 0, n-1);
    free(aux);
    printf("\nThe elements of the sorted arrayy C are: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",c[i]);
    }
    printf("\n");
    removeDuplicates(c, n);
    printf("\nThe elements of the sort array C is :\n");
    int m = removeDuplicates(c, n); // Originally, it was supposed to be m*n, but I'll change it to n*m
    for(int i=0; i<m; i++)
    {
        printf("%d ",c[i]);
    }
    printf("\nThe longest increasing subsequence is: ");
    findLCS(arr, c, n, m);
}