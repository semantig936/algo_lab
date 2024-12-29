#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double compute_iterative(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	double curr, prev, next;
	prev = 0;
	curr = 1;
	for(int i=2; i<=n; i++)
	{
		next = 2*curr + prev;
		prev = curr;
		curr = next;
	}
	return next;
}

double compute_recursive(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	if(n>1)
	{
		return 2*compute_recursive(n-1)+compute_recursive(n-2);
	}
}

double power(double a, int n)
{
	if(n==0)
	{
		return 1;
	}
	if(n==1)
	{
		return a;
	}
	if(n%2 == 0)
	{
		return power(a, n/2)*power(a, n/2);
	}
	else
	{
		return a*power(a, n/2)*power(a, n/2);
	}
}

double compute_formula(int n)
{
	double i_n;
	double a = 1 + sqrt(2);
	double b = 1 - sqrt(2);
	i_n = (power(a, n)-power(b, n))/(2*sqrt(2));
	return i_n;
}

//same technique as normal power, only using matrix instead of number
double** compute_mat_power(double** mat, int n)
{
	double** new_mat = (double**)malloc(2*sizeof(double*));
	for(int i=0; i<2; i++)
	{
		new_mat[i] = (double*)malloc(2*sizeof(double*));
		new_mat[i][0] = 0;
		new_mat[i][1] = 0;
	}
	// new_mat = {{0,0},{0,0}};

	if(n==0)
	{
		new_mat[0][0] = 1;
		new_mat[0][1] = 0;
		new_mat[1][0] = 0;
		new_mat[1][1] = 1;
		return new_mat;
	}
	if(n==1)
	{
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				new_mat[i][j] = mat[i][j];
			}
		}
		return new_mat;
	}
	if(n%2 == 0)
	{
		double** m1 = (double**)malloc(2*sizeof(double*));
		for(int i=0; i<2; i++)
		{
			m1[i] = (double*)malloc(2*sizeof(double));
		}
		m1 = compute_mat_power(mat, n/2);
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				for(int k=0; k<2; k++)
				{
					new_mat[i][j] += m1[i][k]*m1[k][j];
				}
			}
		}
	}
	else
	{
		double** temp = (double**)malloc(2*sizeof(double*));
		for(int i=0; i<2; i++)
		{
			temp[i] = (double*)malloc(2*sizeof(double));
			temp[i][0] = 0;
			temp[i][1] = 0;
		}
		double** m1 = (double**)malloc(2*sizeof(double*));
		for(int i=0; i<2; i++)
		{
			m1[i] = (double*)malloc(2*sizeof(double));
		}
		m1 = compute_mat_power(mat, n/2);
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				for(int k=0; k<2; k++)
				{
					temp[i][j] += m1[i][k]*m1[k][j];
				}
			}
		}
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<2; j++)
			{
				for(int k=0; k<2; k++)
				{
					new_mat[i][j] += mat[i][k]*temp[k][j];
				}
			}
		}
	}
	return new_mat;
}

double compute_fast_without_division(int n)
{
	//double mat = {{2.0, 1.0},{1.0, 0.0}};
	double** mat = (double**)malloc(2*sizeof(double*));
	for(int i=0; i<2; i++)
	{
		mat[i] = (double*)malloc(2*sizeof(double));
	}
	mat[0][0] = 2.0;
	mat[0][1] = 1.0;
	mat[1][0] = 1.0;
	mat[1][1] = 0.0;
	double** final = (double**)malloc(2*sizeof(double*));
	for(int i=0; i<2; i++)
	{
		final[i] = (double*)malloc(2*sizeof(double));
	}
	final = compute_mat_power(mat, n-1);
	return final[0][0];

}

int main()
{
	int n;
	printf("Write n: ");
	scanf("%d",&n);

	double time_spent = 0.0;
	clock_t begin1 = clock();
	double In1 = compute_iterative(n);
	clock_t end1 = clock();
	time_spent += (double)(end1-begin1)/CLOCKS_PER_SEC;
	printf("\nIterative result is: %lf",In1);
	printf("\nTime elapsed is: %f",time_spent);

	time_spent = 0.0;
	clock_t begin2 = clock();
	double In2 = compute_recursive(n);
	clock_t end2 = clock();
	time_spent += (double)(end2-begin2)/CLOCKS_PER_SEC;
	printf("\nRecursive result is: %lf",In2);
	printf("\nTime elapsed is: %f",time_spent);

	time_spent = 0.0;
	clock_t begin3 = clock();
	double In3 = compute_formula(n);
	clock_t end3 = clock();
	time_spent += (double)(end3-begin3)/CLOCKS_PER_SEC;
	printf("\nComputing using formula, the result is: %lf",In3);
	printf("\nTime elapsed is: %lf",time_spent);

	time_spent = 0.0;
	clock_t begin4 = clock();
	double In4 = compute_fast_without_division(n);
	clock_t end4 = clock();
	time_spent += (double)(end3-begin3)/CLOCKS_PER_SEC;
	printf("\nComputing fast without division, answer is: %lf",In4);
	printf("\nTime elapsed is: %lf",time_spent);

	printf("\n");
	return 0;
}