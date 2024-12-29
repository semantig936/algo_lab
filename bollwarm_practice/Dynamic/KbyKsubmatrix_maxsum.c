#include<stdio.h>
#include<stdlib.h>

void maxSum(int** arr, int m, int n, int k)
{
    int** aux = (int**)malloc((m+1)*sizeof(int*));
    for(int i=0; i<=m; i++)
    {
        aux[i] = (int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0; i<=m; i++)
    {
        aux[i][0] = 0;
    }
    for(int i=0; i<=n; i++)
    {
        aux[0][i] = 0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            aux[i][j] = arr[i-1][j-1] + aux[i-1][j] + aux[i][j-1] - aux[i-1][j-1];
        }
    }
    int max_sum = -10000;
    int im, jm;
    for(int i=0; i<(m-k+1); i++)
    {
        for(int j=0; j<(n-k+1); j++)
        {
            int sum =  aux[i+k][j+k] - aux[i+k][j] - aux[i][j+k] + aux[i][j];
            if(sum > max_sum)
            {
                max_sum = sum;
                im = i;
                jm = j;
            }
        }
    }
    printf("Maximum sum of submatrix is: %d",max_sum);
    printf("\nThe desired matrix is: ");
    for(int i=im; i<im+k; i++)
    {
        printf("\n");
        for(int j=jm; j<jm+k; j++)
        {
            printf("%d ",arr[i][j]);
        }
    }
}

int main()
{
    int m, n, k;
    printf("Enter the values of m, n and k: ");
    scanf("%d %d %d",&m,&n,&k);
    int** arr = (int**)malloc(m*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        arr[i] = (int*)malloc(n*sizeof(int));
    }
    //taking input
    printf("Enter the elements in the matrix: ");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    maxSum(arr, m, n, k);
}