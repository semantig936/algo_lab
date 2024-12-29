#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int minCost(int* freq, int i, int j, int level)
{
    if(i > j)
    {
        return 0;
    }
    int optima = INT_MAX;
    for(int k=i; k<=j; k++)
    {
        int leftCost = minCost(freq, i, k-1, level+1);
        int rightCost = minCost(freq, k+1, j, level+1);
        int cost = level*freq[k] + leftCost + rightCost;
        if(cost < optima)
        {
            optima = cost;
        }
    }
    //printf("\nValue of optima is: %d",optima);
    return optima;
}

int main()
{
    int n;
    printf("Enter the total no. of different elements: ");
    scanf("%d",&n);
    int* freq = (int*)malloc(n*sizeof(int));
    printf("\nEnter the frequencies of each element one by one: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&freq[i]); // the elemetns of frequency are the frequency of the elements when arranged in ascending order
    }
    printf("\nThe frequency array is:");
    for(int i=0; i<n; i++)
    {
        printf("%d ",freq[i]);
    }
    int optima = minCost(freq, 0, n-1, 1);
    printf("\nThe desired optimal cost is: %d",optima);
    return 0;
}