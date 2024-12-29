#include<stdio.h>
#include<stdlib.h> 

// v = no. of votes for that particular recursion, p = no. of parties taken into consideration, size and total_voes store th eoriginal numbers for the check
void vote_dist(int* arr, int* c, int p, int v, int k, int start, int size, int total_votes)
{
	// Base case
	if(p==0 || v==0)
	{
		if (p == 0) {
			arr[size - 1] += v;
		}
		if(check(arr, c, k, total_votes))
		{
			print_result(arr, c, size, k);
		}
		arr[size - 1] -= v;

		return;
	}
	case1(arr, c, p, v, k, start, size, total_votes);
	case2(arr, c, p, v, k, start, size, total_votes);
}

void case1(int* arr, int* c, int p, int v, int k, int start, int size, int total_votes)
{

	int incr = 1;
	if (p == 1)
		incr = v;
	arr[start] += incr;
	vote_dist(arr, c, p, v-incr, k, start, size, total_votes);	
	arr[start] -= incr;
}

void case2(int* arr, int* c, int p, int v, int k, int start, int size, int total_votes)
{
	vote_dist(arr, c, p-1, v, k, start+1, size, total_votes);
}

int check(int* arr, int* c, int k, int total_votes)
{
	if(sum_coalition(arr, c, k) > total_votes/2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// sum of all the votes given in the coalition
int sum_coalition(int* arr, int* c, int k)
{
	int sum = 0;
	for(int i=0; i<k; i++)
	{
		sum = sum + arr[c[i]-1];
	}
	return sum;
}

void print_result(int* arr, int* c, int p, int k)
{
	for(int i=0; i<p; i++)
	{
		printf("%d: %d\t",(i+1),arr[i]);
	}
	printf("\nTotal votes for the coalition: %d\n", sum_coalition(arr, c, k));
}

int main()
{
	int v, p; // v = no. of voters, p = no. of parties
	printf("Write the number of voters: ");
	scanf("%d",&v);
	if(v>30)
	{
		return 0;
	}
	printf("\nWrite the number of parties: ");
	scanf("%d",&p);
	if(p>10)
	{
		return 0;
	}
	int k; // no. of parties in the coalition
	printf("\nWrite the numbers of parties in the coalition: ");
	scanf("%d",&k);
	int* c = (int*)malloc(k*sizeof(int));
	printf("Write the parties in the coalition: ");
	for(int i=0; i<k; i++)
	{
		scanf("%d",&c[i]);
	}
	// arr is the array of the the number of votes to each party from 0 to p-1
	int* arr = (int*)malloc(p*sizeof(int));
	for(int i=0; i<p; i++)
	{
		arr[i] = 0; // initially putting all votes = 0
	}
	vote_dist(arr, c, p, v, k, 0, p, v);
	return 0;
}