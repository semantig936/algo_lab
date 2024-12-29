#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maxValue(int prices[], int n)
{
    if(n<=0)
    {
        return 0;
    }
    int maxval = INT_MIN;
    int val = 0;
    for(int i=1; i<=n; i++)
    {
        val = prices[i-1] + maxValue(prices, n-i);
        if(val>maxval)
        {
            maxval = val;
        }
    }
    return maxval;
}

int main()
{
    int n;
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    printf("Enter the length of the rod(upto 8m): ");
    scanf("%d",&n);
    int M = maxValue(prices, n);
    printf("\nMaximum value possible is: %d",M);
    return 0;
}