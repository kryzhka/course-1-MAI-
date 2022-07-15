#include <stdio.h>

int main()
{
	printf("Введите длинну массива больше 0 и меньше 10 \n");
	int n;
	scanf("%d",&n);
	int M[9][9];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			M[i][j]=(i+1)*10+j+1;
		}
	}
	printf("Исходная матрица:\n");
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			printf("%d ",M[i][j]);
		}
		printf("%c",'\n');
	}
	printf("Результат:\n");
	for(int r=-n+1;r<n;++r)
	{
		for(int k=0;k<n;++k)
		{
			if(k+r<n&&k+r>=0)
			printf("%d ",M[n-k-1][k+r]);
		}
	}
	
} 