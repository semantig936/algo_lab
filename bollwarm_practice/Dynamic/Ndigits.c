#include<stdio.h>
#include<stdlib.h>

// simpler to do the crappy stuff which they've done

int count(char arr[4][3], int n, int x, int y, int c)
{
    // base cases
    if(x<0 || y<0 || x>=4 || y>=3)
    {
        return 0;
    }
    if(x==3 && (y==0 || y==2))
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }
    c = 1 + count(arr, n-1, x-1, y, c) + count(arr, n-1, x+1, y, c) + count(arr, n-1, x, y-1, c) + count(arr, n-1, x, y+1, c);
    return c;
}

int main()
{
    int n;
    printf("Enter the number of elements you want in the substring: ");
    scanf("%d",&n);
    char keypad[4][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
    int c = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            c = c + count(keypad, n, i, j, 0);
            //printf("\nConsidering %c, c=%d ", keypad[i][j], c);
        }
    }
    printf("\nThe total no. of %d length strings possible are %d ",n,c);
    return 0;
}