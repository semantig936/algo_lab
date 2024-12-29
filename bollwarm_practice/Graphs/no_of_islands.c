#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//relate - Knight tour problem - OR lab, but fact remains that this doesn't work

bool isSafe(int** map, int** visited, int m, int n, int row, int col)
{
    printf("\nIn isSafe, row = %d, col = %d",row,col);
    return ((row>=0 && row<m) && (col>=0 && col<n) && (visited[row][col]==0));
}

void DFS(int** map, int** visited, int m, int n, int x, int y)
{
    printf("In DFS, x=%d, y=%d",x,y);
    int hor[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int ver[] = {-1, 0, 1, 1, -1, -1, 0, 1};
    visited[x][y] = 1;
    for(int i=0; i<8; i++)
    {
        if(isSafe(map, visited, m, n, x+hor[i], y+ver[i]))
        {
            DFS(map, visited, m, n, x+hor[i], y+ver[i]);
        }
    }
}

int numIslands(int** map, int m, int n)
{
    int** visited = (int**)malloc(m*sizeof(int*));
    for(int i=0; i<m; i++)
    {
        visited[i] = (int*)malloc(n*sizeof(int));
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i][j] = 0;
        }
    }
    int count = 0; //for the count of the total number of islands
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(map[i][j]==0 && !visited[i][j])
            {
                DFS(map, visited, m, n, i, j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int m, n;
    printf("Enter the dimensions of your matrix: ");
    scanf("%d %d",&m,&n);//memory allocation of a matrix with m rows and n columns 
    int** map = (int**)malloc(m*sizeof(int));
    for(int i=0; i<m; i++)
    {
        map[i] = (int*)malloc(n*sizeof(int));
    }
    printf("Enter the elements of the map: \n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
    int count = numIslands(map, m, n);
    printf("The number of islands on this map are: %d",count);
    return 0;
}