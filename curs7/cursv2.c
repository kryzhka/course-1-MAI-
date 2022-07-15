#include <stdio.h>

float module(float k)
{
	if(k<0)
		return -k;
	return k;
}

void short_to_full(float **matrix, int n, int m, int k, int *cip, int *pi, float *ye)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	int p, l;
	for (int i = 0; i < n; ++i)
	{
		if (i == n - 1)
			p = k + 1;
		else
			p = cip[i + 1];
		if (p == 0)
		{
			p = cip[i + 2];
		}
		l = cip[i];
		if (l != 0)
		{
			for (int j = l - 1; j < p - 1; ++j)
			{
				matrix[i][pi[j] - 1] = ye[j];
			}
		}
	}
}

void full_to_short(float **matrix, int n, int m, int *cip, int *pi, float *ye)
{
	int k = 0, zero;
	for (int i = 0; i < n; ++i)
	{
		cip[i] = k + 1;
		zero = 0;
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] != 0)
			{
				ye[k] = matrix[i][j];
				pi[k] = j + 1;
				k += 1;
				zero += 1;
			}
		}
		if (zero == 0)
			cip[i] = 0;
	}
}
void transform_full_matrix(int n, int m, float min_diff, float **matrix)
{
	float epsilon=1.0;
	while (1+epsilon>1)
		epsilon/=2;
	printf("epsilon is %f\n",epsilon);
	float **matrix_modify;
	matrix_modify = new float*[n];
	for(int i=0;i<n;++i)
		matrix_modify[i]=new float[m];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
			matrix_modify[i][j]=matrix[i][j];
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if((matrix_modify[i][j]>=min_diff-epsilon)&&(matrix_modify[i][j]<=min_diff+epsilon))
			{
				for(int k=0;k<n;++k)
				{
					if(matrix_modify[k][j]==matrix[k][j])
						matrix[k][j]=matrix[k][j]/matrix_modify[i][j];
				}
				for(int k=0;k<m;++k)
				{
					if(matrix_modify[i][k]==matrix[i][k])
					matrix[i][k]=matrix[i][k]/matrix_modify[i][j];
				}
			}
		}
	}
	delete[] matrix_modify;
}



void print_short_matrix(int n,int k, int *cip, int *pi, float *ye)
{
	printf("CIP: ");
	for(int i=0;i<n;++i)
		printf("%d ",cip[i]);
	printf("\n");
	printf("PI: ");
	for(int i=0;i<k;++i)
		printf("%d ",pi[i]);
	printf("\n");
	printf("YE: ");
	for(int i=0;i<k;++i)
		printf("%.1f ",ye[i]);
	printf("\n");
}

void print_full_matrix(int n, int m, float **matrix)
{
	printf("Full matrix:\n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			printf("%.1f ",matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	float **matrix,*ye;
	int *cip,*pi;
	int n,m,k;
	float p,min_diff,min_element;
	printf("n = \n");scanf("%d",&n);
	printf("m = \n");scanf("%d",&m);
	printf("k = \n");scanf("%d",&k);
	printf("p = \n");scanf("%f",&p);
	if(p==0)
	{
		printf("ERROR ERROR ERROR нельзя делить на 0!!!!!!!!!\n");
	
		return 1;
	}
	matrix = new float*[n];
	for(int i=0;i<n;++i)
		matrix[i]=new float[m];
	cip=new int[n];
	pi=new int[k];
	ye=new float[k];
	printf("CIP: ");
	for(int i=0;i<n;++i)
		scanf("%d",&cip[i]);
	printf("\n");
	printf("PI: ");
	for(int i=0;i<k;++i)
		scanf("%d",&pi[i]);
	printf("\n");
	printf("YE: ");
	min_diff=p;
	for(int i=0;i<k;++i)
	{
		scanf("%f",&ye[i]);
		if(module( p-ye[i])<min_diff)
		{
			min_element=ye[i];
			min_diff=p-ye[i];
		}
	}
	printf("\n");
	print_short_matrix(n, k, cip, pi, ye);
	short_to_full(matrix, n, m,k, cip, pi, ye);
	print_full_matrix(n, m, matrix);
	transform_full_matrix(n, m, min_element, matrix);
	print_full_matrix(n, m, matrix);
	full_to_short(matrix, n, m, cip, pi, ye);
	print_short_matrix(n, k, cip, pi, ye);
	delete[] cip;
	delete[] pi;
	delete[] ye;
	delete[] matrix;
	return 0;

}