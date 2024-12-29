#include<stdio.h>
#include<stdlib.h>


int* T1(int n)
{
	int* t1 = (int*)malloc(n*sizeof(int));
	t1[0] = 2;
	t1[1] = 1;
	for(int i=2; i<n; i++)
	{
		t1[i] = t1[i-1] - 2*t1[i-2];
	}
	return t1;
}

int* T2(int n)
{
	int* t2 = (int*)malloc(n*sizeof(int));
	t2[0] = 2;
	t2[1] = 1;
	for(int i=2; i<n; i++)
	{
		t2[i] = t2[i-1] - t2[i-2];
	}
	return t2;
}


void Merge(int* arr, int* aux, int low, int mid, int high)
{
	int k=low, i=low, j=mid+1;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			aux[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			aux[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		aux[k++] = arr[i++];
	}
	while(j<=high)
	{
		aux[k++] = arr[j++];
	}
	for(int x=low; x<=high; x++)
	{
		arr[x] = aux[x];
	}
}


// part of fCombinedSort
void bubbleSort(int* arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int* bucketSort(int* arr, int n)
{
	int bucket[4];
	int* newarr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<4; i++)
	{
		bucket[i] = 0;
	}
	//O(n) timecomplexity
	for(int i=0; i<n; i++)
	{
		if(arr[i]==-2)
		{
			bucket[0]++;
		}
		if(arr[i]==-1)
		{
			bucket[1]++;
		}
		if(arr[i]==1)
		{
			bucket[2]++;
		}
		if(arr[i]==2)
		{
			bucket[3]++;
		}
	}
	int j=0;
	//Again O(n) time complexity
	for(int i=0; i<4; i++)
	{
		while(bucket[i]!=0)
		{
			if(i==0)
				newarr[j]=-2;
			if(i==1)
				newarr[j]=-1;
			if(i==2)
				newarr[j]=1;
			if(i==3)
				newarr[j]=2;
			j++;
			bucket[i]--;
		}
	}
	return newarr;

}
// The desired function for fCombinedSort
int f(int n)
{
	int f = 1;
	// We need a function such that f(n)<O(log(n)) for all values of n, k
	return f;
}

void fCombinedSort(int* arr, int* aux, int low, int high, int n)
{
	if(n>f(n))
	{
		if(high<=low)
		{
			return;
		}
		int mid = low + (high-low)/2;
		fCombinedSort(arr, aux, low, mid, mid-low+1);
		fCombinedSort(arr, aux, mid+1, high, high-mid);
		Merge(arr, aux, low, mid, high);
	}
	else
	{
		bubbleSort(arr, n);
	}
}


int main()
{
	int n;
	printf("Input a value for n: ");
	scanf("%d",&n);
	printf("\n");

	int* A = T1(n);
	int* B = T2(n);

	printf("The unsorted array A: \n");
	for(int i=0; i<n; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");

	printf("The unsorted array B: \n");
	/*After printing B, it is evident that B array only has the array 
	[2,1,-1,-2,-1,1] repeated over and over again. So the sort method must be chosen
	according. And minimum time complexity in this case is for bucket sort*/ 
	for(int i=0; i<n; i++)
	{
		printf("%d ",B[i]);
	}
	printf("\n");

	int* aux = (int*)malloc(n*sizeof(int));
	fCombinedSort(A, aux, 0, n-1, n);
	printf("The sorted array A:\n");
	for(int i=0; i<n; i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
 
	B = bucketSort(B, n);
	printf("The sorted array B:\n");
	for(int i=0; i<n; i++)
	{
		printf("%d ",B[i]);
	}
	printf("\n");
}