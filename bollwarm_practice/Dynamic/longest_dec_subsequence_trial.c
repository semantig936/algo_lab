#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int low, int mid, int high, int* aux)
{
    int i=low; 
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i] > arr[j])
        {
            aux[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            aux[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        aux[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        aux[k] = arr[j];
        k++;
        j++;
    }
    for(int l=low; l<=high; l++)
    {
        arr[l] = aux[l];
    }
}

void mergesort(int* arr, int low, int high, int* aux)
{
    if(high <= low)
    {
        return;
    }
    int mid = (low + high)/2;
    mergesort(arr, low, mid, aux);
    mergesort(arr, mid+1, high, aux);
    merge(arr, low, mid, high, aux);
}

void print_LCS(int m, int n, int* x, int* y, int** lookup)
{
    if(m==0 || n==0)
    {
        return;
    }
    if(x[m-1] == y[n-1])
    {
        print_LCS(m-1, n-1, x, y, lookup);
        printf("%d ",x[m-1]);
    }
    else
    {
        if(lookup[m-1][n] > lookup[m][n-1])
        {
            print_LCS(m-1, n, x, y, lookup);
        }
        else
        {
            print_LCS(m, n-1,x, y, lookup);
        }
    }
}

void LCS(int m, int n, int* x, int* y)
{
    int** lookup = (int**)malloc((m+1)*sizeof(int*));
    for(int i=0; i<=m; i++)
    {
        lookup[i] = (int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0; i<=m; i++)
    {
        lookup[i][0] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        lookup[0][i] = 0;
    }
    for(int i=1; i<=m; i++)
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
    print_LCS(m, n, x, y, lookup);
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements in the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int* arr1 = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        arr1[i] = arr[i];
    }
    int* aux = (int*)malloc(n*sizeof(int));
    mergesort(arr1, 0, n-1, aux);
    LCS(n, n, arr, arr1);
    return 0;
}