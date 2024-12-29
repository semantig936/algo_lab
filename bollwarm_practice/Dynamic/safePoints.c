#include<stdio.h>
#include<stdlib.h>

// I identified the problem - the loop is getting terminated

int max(int x, int y)
{
    if(x>y)
    return x;
    else
    return y;
}

int min(int x, int y)
{
    if(x<y)
    return x;
    else
    return y;
}

int collect(int** arr, int m, int n, int x, int y, int c)
{
    printf("\nx=%d, y=%d, c=%d",x,y,c);
    if(arr[x][y]==-1)
    {
        return 0;
    }
    if(x<0 || x>=m || y<0 || y>=n)
    {
        return 0;
    }
    if(x%2 == 0)
    {
        c = arr[x][y] + max(collect(arr,m, n, x-1, y, c), collect(arr,m, n, x, y-1, c));
    }
    else
    {
        c = arr[x][y] + max(collect(arr,m, n,  x+1, y, c), collect(arr,m, n, x, y-1, c));
    }
    return c;
}

int main()
{
    int m, n;
    printf("Enter the dimensions of the matrix: ");
    scanf("%d %d",&m,&n);
    int** arr = (int**)malloc(m*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        arr[i] = (int*)malloc(n*sizeof(int));
    }
    printf("\nPopulate the matrix with -1, 0 or 1:\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int max_count = 0;
    int c;
    printf("\nThe matrix entered is:\n");
    for(int i=0; i<m; i++)
    {
        //printf("i=%d",i);
        for(int j=0; j<n; j++)
        {
            //printf("\nWhy can't it enter this loop?!");
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\nAbout to enter the main loop");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            c = collect(arr, m, n, i, j, 0);
            printf("\nc=%d",c);
            if(c>max_count)
            {
                max_count = c;
            }
        }
    }
    printf("\nMaximum count of 1's is: %d", max_count);
    return 0;
}