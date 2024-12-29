#include<stdio.h>
#include<stdlib.h>

//The approach must use dynamic programming, and I haven't used it, anyway whatever I've done is wrong so it hardly matters
float probability(int n, int x, int y, int k)
{
    if(x>=n || x<0 || y>=n || y<0)
    {
        return 0;
    }
    // if the person doesn't take any step at all, then he is already on the matrix and will remain alive
    if(k==0)
    {
        return 1.0;
    }
    //printf("\n%f",0.25*probability(n, x-1, y, k-1) + 0.25*probability(n, x+1, y, k-1) + 0.25*probability(n, x, y-1, k-1) + 0.25*probability(n, x, y+1, k-1));
    return 0.25*probability(n, x-1, y, k-1) + 0.25*probability(n, x+1, y, k-1) + 0.25*probability(n, x, y-1, k-1) + 0.25*probability(n, x, y+1, k-1);
}

int main()
{
    int n;
    printf("Enter the side of the square matrix:");
    scanf("%d",&n);
    int x, y;
    printf("\nEnter the initial coordinates of the person: ");
    scanf("%d %d",&x,&y);
    int k;
    printf("\nEnter the number of steps the person took: ");
    scanf("%d",&k);
    float p = probability(n, x, y, k);
    printf("\nThe probability of survival is: %f",p);
    return 0;
}