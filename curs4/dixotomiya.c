//┌ │ ─ ┬ ┐ ┼ ├ ┤ └ ┴ ┘
#include <stdio.h>
#include <math.h>
#include "func.h"
double f1(double);
double f2(double);
double f3(double);
double eps = 0.0000001;
double dabs(double x) { 
	return (x > 0 ? x : -x);
}

double dichotomy(double f(double), double a, double b) {
	printf("┌───────┬───────┬───────┬──────────────────┬─────────────────┬────────┐\n");
	printf("│   a   │   b   │(a+b)/2│ f(a)*f((a+b)/2)>0│f(b)*f((a+b)/2)>0│ |x-x*| │\n");
	printf("├───────┼───────┼───────┼──────────────────┼─────────────────┼────────┤\n");
	double prevX = b, x = (a + b) / 2.;
	printf("│%5.5f│%5.5f│%5.5f│      %5s       │      %5s      │%5.6f│\n",a,b,x,f(a)*f((a+b)/2)>0 ? "True" : "False",f(b)*f((a+b)/2)>0 ? "True" : "False",dabs(a-b));
	while(dabs(prevX - x) > eps) {
		if(f(x)*f(a) > 0)
			a = x;
		else
			b = x;
		prevX = x;
		x = (a + b) / 2.;
		printf("│%5.5f│%5.5f│%5.5f│      %5s       │      %5s      │%5.6f│\n",a,b,x,f(a)*f((a+b)/2)>0 ? "True" : "False",f(b)*f((a+b)/2)>0 ? "True" : "False",dabs(a-b));
	}
	printf("└───────┴───────┴───────┴──────────────────┴─────────────────┴────────┘\n");
	return x;
}
int main()
{	printf("Функция 1\n");
	printf("Корень, найденый методом деления пополам: %f\n",dichotomy(f1,1,3));
	printf("Функция 2\n");
	printf("Корень, найденый методом деления пополам: %f\n",dichotomy(f2,4,5));
	printf("Функция 3\n");
	printf("Корень, найденый методом деления пополам: %f\n",dichotomy(f3,4,5));
}