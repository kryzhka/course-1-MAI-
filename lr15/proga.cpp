#include <stdio.h> 
int main()
{
	int **a,n=0,k=0;
	int i=0, j=0;
	
	scanf("%d",&n);
	a=new int*[n];
	for(i=0;i<n;i++)
		a[i]=new int[n];
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Исходная матрица:\n");
for(i=0;i<n;i++)
 { for(j=0;j<n;j++)
   { 
     printf(" %3d",a[i][j]);
   } printf("\n");
 }
 long long maxmyltiply=0,currentMyltiply=1,minMyltiply=1;
 int maxmyltiply_index,minMyltiply_index;
 for(j=0;j<n;++j)
 	minMyltiply*=a[0][j];

 	for(i=0;i<n;++i)
	{
	 	for(j=0;j<n;++j)
	 	{
	 		currentMyltiply*=a[i][j];
	 	}
	 	if(currentMyltiply<=minMyltiply)
	 	{
	 		minMyltiply=currentMyltiply;
	 		minMyltiply_index=i;
	 	}
	 	if(maxmyltiply<=currentMyltiply)
	 	{
	 		maxmyltiply=currentMyltiply;
	 		maxmyltiply_index=i;
	 	}
	 	currentMyltiply=1;
  }
currentMyltiply=1;
 
 int c;
 for(j=0;j<n;++j)
 {
 	c=a[minMyltiply_index][j];
 	a[minMyltiply_index][j]=a[maxmyltiply_index][j];
 	a[maxmyltiply_index][j]=c;

 }
 printf("Матрица, полученная нами:\n");
 for(i=0;i<n;i++)
 { for(j=0;j<n;j++)
   { 
     printf(" %3d",a[i][j]);
   } printf("\n");
 }

} 