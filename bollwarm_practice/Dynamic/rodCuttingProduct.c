#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int product(int n)
{
    if(n<=0)
    {
        return 1;
    }
    int maxprod = INT_MIN;
    int prod = 1;
    for(int i=1; i<=n; i++)
    {
        prod = i*product(n-i);
        if(prod > maxprod)
        {
            maxprod = prod;
        }
    }
    return maxprod;
}

int main()
{
    int n;
    printf("Enter the length of the rod: ");
    scanf("%d",&n);
    printf("\nThe maximum product is: %d",product(n));
}