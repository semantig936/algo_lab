#include<stdio.h>
#include<stdlib.h>

void init(int* A, int* D, int n)
{
	for(int i=0; i<n; i++)
	{
		A[i]=i+1;
	}
	D[0] = 0;
	for(int i=1; i<n; i++)
	{
		D[i]=-1;
	}
	int invCount=0;
}

void print_index_table(int* a, int n)
{
	int* it = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(a[j]<a[i])
			{
				it[a[j]-1]++;
			}
		}
	}
	for(int i = 0; i< n-1; i++)
	{
		printf("%d,",it[i]);
	}
	printf("%d",it[n-1]);
}


int ind(int* a, int n)
{
	int index = 0;
	for(int i=0; i<n-1; i++)
	{
		if(a[i]>a[i+1])
			index = index + (i+1);
	}
	return index;
}

int genNext(int* A, int* D, int n, int invCount, int count)
{
	int max = 0;
	int k = -1;
	int d;
	for(int i = 0; i<n; i++)
	{
		if(D[i]!=0)
		{
			if(A[i]>max)
			{
				max = A[i];
				k = i;
				d = D[i];
			}
		}
	}
	int temp;
	temp  = A[k];
	A[k] = A[k+d];
	A[k+d] = temp;
	if(d>0 && A[k+d]<A[k])
	{
		invCount++;
	}
	else if(d<0 && A[k+d]>A[k])
	{
		invCount++;
	}
	else
	{
		invCount--;
	}
	if(k+d == 0 || k+d == n-1)
	{
		D[k+d] = 0;
	}
	else if(A[k+d+d]>A[k+d])
	{
		D[k] = 0;
	}
	for(int i=0; i<n; i++)
	{
		if(A[i]>max && D[i]==0)
		{
			if(i>k+d)
			{
				D[i] = -1;
			}
			else
			{
				D[i] = 1;
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\t %d \t %d \t ", invCount, ind(A,n));
	print_index_table(A, n);
	printf("\n");
	
	/*
	for(int i=0; i<n; i++)
	{
		if(D[i]!=0)
		{
			genNext(A, D, n, invCount, count-1);
		}
	}
	*/

	if(count-1!=0)
		genNext(A, D, n, invCount, count-1);
	return invCount;

}

int main()
{
	int n;
	printf("Please enter the value of n:\n");
	scanf("%d",&n);
	//Just to keep a count of the total number of permutations there will be
	int fact = 1;
	for(int i=1; i<=n; i++)
	{
		fact = fact*i;
	}
	int* A = (int*)malloc(n*sizeof(int));
	int* D = (int*)malloc(n*sizeof(int));
	init(A, D, n);
	for(int i = 0; i<n; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\t 0 \t 0\t ");
	print_index_table(A, n);
	printf("\n");
	int invCount = 0;
	genNext(A, D, n, invCount, fact-1);
	for(int i=0; i<n; i++)
		printf("%d ",D[i]);
}