#include<stdio.h>
#include<stdlib.h>

void printMatrix(int** mat, int row_start, int col_start, int row_end, int col_end)
{
    for(int i=row_start; i<=row_end; i++)
    {
        for(int j=col_start; j<=col_end; j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

void maxSum(int** mat, int** aux, int n)
{
    int sum;
    int maxsum = -1000;
    int row_start, col_start, row_end, col_end;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=i; k<n; k++)
            {
                for(int l=j; l<n; l++)
                {
                    sum = aux[k+1][l+1] - aux[k+1][j] - aux[i][l+1] + aux[i][j];
                    if(sum > maxsum)
                    {
                        maxsum = sum;
                        row_start = i;
                        col_start = j;
                        row_end = k;
                        col_end = l;
                    }
                }
            }
        }
    }
    printf("\nThe maximum sum is: %d",maxsum);
    printf("\n");
    printMatrix(mat, row_start, col_start, row_end, col_end);
}

void SubMatrixSum(int** mat, int n)
{
    //this auxillary matrix will store sum of the submatrix from (0,0) to (i,j)
    int** aux = (int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<=n; i++)
    {
        aux[i] = (int*)malloc(n*sizeof(int));
    }
    for(int i=0; i<=n; i++)
    {
        aux[i][0] = 0;
    }
    for(int j=0; j<=n; j++)
    {
        aux[0][j] = 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            aux[i][j] = mat[i-1][j-1] + aux[i-1][j] + aux[i][j-1] - aux[i-1][j-1];
        }
    }
    maxSum(mat, aux, n);
}

int main()
{
    int n;
    printf("Enter the length of side of the matrix: ");
    scanf("%d",&n);
    int** mat = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        mat[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter the elements of the matrix: ");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    SubMatrixSum(mat, n);
    return 0;
}