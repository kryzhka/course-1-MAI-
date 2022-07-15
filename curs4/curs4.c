#include <math.h>
#include <stdio.h>
#include "locale.h"
#include "func.h"

double dabs(double);
double dichotomy(double f(double), double, double);
double iteration(double f(double), double, double);
double tangent(double f(double), double F(double), double, double);
double chord(double f(double), double, double);
double f1(double);
double f1_x(double);
double f1_p(double);
double f2(double);
double f2_x(double);
double f2_p(double);
double f3(double);
double f3_x(double);
double f3_p(double);

int main()
{
	printf("Корень для функции f1\n");
	printf("Корень, найденый методом деления пополам: %f\n",dichotomy(f1,1,3));
	printf("Корень, найденый методом итераций: не удовлетворяет условию достаточности\n");
	printf("Корень, найденый методом касательных:     %f\n",tangent(f1,f1_p,1,3));
	printf("Корень, найденый методом хорд:            %f\n",chord(f1,1,3));
	printf("Корень для функции f2\n");
	printf("Корень, найденый методом деления пополам: %f\n",dichotomy(f2,4,5));
	printf("Корень, найденый методом итераций:        %f\n",iteration(f2_x,4,5));
	printf("Корень, найденый методом касательных:     %f\n",tangent(f2,f2_p,4,5));
	printf("Корень, найденый методом хорд:            %f\n",chord(f2,4,5));
	printf("Корень для функции f3\n");
	printf("Корень, найденый методом деления пополам: %f\n",dichotomy(f3,4,5));
	printf("Корень, найденый методом итераций:        %f\n",iteration(f3_x,4,5));
	printf("Корень, найденый методом касательных:     %f\n",tangent(f3,f3_p,4,5));
	printf("Корень, найденый методом хорд:            %f\n",chord(f3,4,5));
}