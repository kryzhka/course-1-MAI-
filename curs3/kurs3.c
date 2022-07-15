#include <stdio.h>
#include <math.h>

double my_log(const double& epsilon,const double& x,int& n)
{
	double p=x/2,S=p;
	while(abs(p)>epsilon)
		{
			++n;
			if(n>99)
				break;
			p=-p*x*(n-1)/(n*2);
			S+=p;
		}
	return S;
}

int main()
{	
	double x,S,f, epsilon= 1.0;
	float a=-1.0, b = 1.0, h = (b-a)/10;
	int n;
	while (1+epsilon>1)
		epsilon/=2;
	printf("Computer epsilon: %.20f\n",epsilon);
	printf("┌──────┬────────────────────────┬────────────────────────┬────┐\n");
	printf("│  X   │            Sum         │           f(x)         │  n │\n");
	for(x=a;x<=b;x+=h)
	{
		n=1;
		S=log(2)+my_log(epsilon,x,n);
		f=log(x+2);
		printf("├──────┼────────────────────────┼────────────────────────┼────┤\n");
		if(x>=0)
		printf("│ %.2f │",x);
		else
		printf("│%.2f │",x);
		printf(" %.20f │ %.20f │ %2d │\n",S,f,n);		
	}
	
		x=1.0;
		n=1;
		S=log(2)+my_log(epsilon,x,n);
		f=log(x+2);
		printf("├──────┼────────────────────────┼────────────────────────┼────┤\n");
		printf("│ %.2f │ %.20f │ %.20f │ %d │\n",x,S,f,n);
		printf("└──────┴────────────────────────┴────────────────────────┴────┘\n");
}