#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, p;
    printf("Enter N: ");
    scanf("%d",&n);
    printf("Enter P: ");
    scanf("%d",&p);
    float** prob = (float**)malloc(n*sizeof(float*));
    for(int i=0; i<n; i++)
    {
        prob[i] = (float*)malloc((p+1)*sizeof(float)); 
    }
    //taking input of the probability matrix
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=p; j++)
        {
            scanf("%f",&prob[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        prob[i][0] = 0; //if 0 people are alloted, then probability of success will be zero
    }
}