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

double iteration(double f(double), double a, double b) {
	printf("┌───────┬───────┬───────┬──────────────────┬───────────┐\n");
	printf("│   a   │   b   │   x   │   x-f(x)/f_p(x)  │ |prevX-x| │\n");
	printf("├───────┼───────┼───────┼──────────────────┼───────────┤\n");
	double prevX = (a+b)/2., x = f(prevX);
	printf("│%5.5f│%5.5f│%5.5f│     %5f     │  %5.6f  │\n",a,b,prevX,x,dabs(prevX-x));

	while(dabs(x-prevX) > eps) {
		prevX = x;
		x = f(x);
		printf("│%5.5f│%5.5f│%5.5f│     %5f     │  %5.6f  │\n",a,b,prevX,x,dabs(prevX-x));
	}
	printf("└───────┴───────┴───────┴──────────────────┴───────────┘\n");
	return x;
}
int main()
{	printf("Функция 1\n");
	printf("Корень, нельзя найти методом итерации\n");
	printf("Функция 2\n");
	printf("Корень, найденый методом итерации: %f\n",iteration(f2_x,4,5));
	printf("Функция 3\n");
	printf("Корень, найденый методом итерации: %f\n",iteration(f3_x,4,5));
}