#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void printLongestPath(int** m, int** l, int i, int j)
{
    if(i==0 && j==0)
    {
        return;
    }
    if(i==0)
    {
        printLongestPath(m, l, i, j-1);
    }
    else if(j==0)
    {
        printLongestPath(m, l, i-1, j);
    }
    else
    {
        if(l[i-1][j] > l[i][j-1])
        {
            printLongestPath(m, l, i-1, j);
        }
        else
        {
            printLongestPath(m, l, i, j-1);
        }
    }
    printf("%d-",m[i][j]);
}

int longestPath(int** m, int n)
{
    int** l = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        l[i] = (int*)malloc(n*sizeof(int));
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            l[i][j] = 0;
        }
    }
    int longest = 0;
    int x, y;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((i>=1) && (abs(m[i][j]-m[i-1][j])==1))
            {
                l[i][j] = l[i-1][j] + 1;
            }
            if((j>=1) && (abs(m[i][j]-m[i][j-1])==1))
            {
                if(l[i][j-1] + 1 > l[i][j])
                {
                    l[i][j] = l[i][j-1] + 1;
                }
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(longest < l[i][j])
            {
                longest = l[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("\n");
    printLongestPath(m, l, x, y);
    return longest;   
}

int main()
{
    int n;
    printf("Enter the value length of side of the square matrix: ");
    scanf("%d",&n);
    int** m = (int**)malloc(n*sizeof(int*));
    for(int i=0; i<n; i++)
    {
        m[i] = (int*)malloc(n*sizeof(int));
    }
    printf("\nEnter the elements of the original matrix:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    int l = longestPath(m, n)  + 1;
    printf("\nThe longest path is: %d",l);
    return 0;
}