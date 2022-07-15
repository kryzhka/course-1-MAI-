#include <stdio.h>

int main()
{
	int a=10,b=30,c=5;
	--c;
	a=a%100;
	printf("%d\n",a%10);
	printf("%d\n",b/c*a);
}