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
double chord(double f(double), double a, double b) {
	printf("┌───────┬───────┬────────┬────────┬───────┬───────┬─────────┐\n");
	printf("│   a   │   b   │   ya   │   yb   │ prevX │   x   │|prevX-x|│\n");
	printf("├───────┼───────┼────────┼────────┼───────┼───────┼─────────┤\n");
	double prevX = b, ya = f(a), yb = f(b);
	double x = (ya*b-yb*a)/(ya-yb);
	printf("│%5.5f│%5.5f│%5.5f│%5.5f│%5.5f│%5.5f│ %5.6f│\n",a,b,ya,yb,prevX,x,dabs(prevX-x));
	while(dabs(prevX - x) > eps) {
		if(ya*f(x) > 0)
			a = x;
		else
			b = x;
		ya = f(a), yb = f(b);
		prevX = x;
		x = (ya*b-yb*a)/(ya-yb);
		printf("│%5.5f│%5.5f│%5.5f│%5.5f│%5.5f│%5.5f│ %5.6f│\n",a,b,ya,yb,prevX,x,dabs(prevX-x));
	}
	printf("└───────┴───────┴────────┴────────┴───────┴───────┴─────────┘\n");
	return x;
}
	
int main()
{	printf("Функция 1\n");
	printf("Корень, найденый методом касательных: %f\n",chord(f1,1,3));
	printf("Функция 2\n");
	printf("Корень, найденый методом касательных: %f\n",chord(f2,4,5));
	printf("Функция 3\n");
	printf("Корень, найденый методом касательных: %f\n",chord(f3,4,5));
}