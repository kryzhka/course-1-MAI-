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

	double tangent(double f(double), double F(double), double a, double b) {
	printf("┌───────┬───────┬───────┬──────────────────┬───────────┐\n");
	printf("│   a   │   b   │   x   │   x-f(x)/f_p(x)  │ |prevX-x| │\n");
	printf("├───────┼───────┼───────┼──────────────────┼───────────┤\n");
	double prevX = (a+b/2.), x = prevX - f(prevX)/F(prevX);
	while(dabs(prevX - x) > eps) {
		prevX = x;
		x = prevX - f(prevX)/F(prevX);
		printf("│%5.5f│%5.5f│%5.5f│     %5f     │  %5.6f │\n",a,b,prevX,x,dabs(prevX-x));
	}
		printf("└───────┴───────┴───────┴──────────────────┴───────────┘\n");
	return x;
}

int main()
{	printf("Функция 1\n");
	printf("Корень, найденый методом касательных: %f\n",tangent(f1,f1_p,1,3));
	printf("Функция 2\n");
	printf("Корень, найденый методом касательных: %f\n",tangent(f2,f2_p,4,5));
	printf("Функция 3\n");
	printf("Корень, найденый методом касательных:     %f\n",tangent(f3,f3_p,4,5));
}