//***********************************f1*******************************
double f1(double x)
{
	return 3*x-14+pow(exp(1.),x)-pow(exp(1.),-x);
}

double f1_p(double x)
{
	return 3+pow(exp(1.),x)+pow(exp(1.),-x);
}
//***********************************f2*******************************
double f2(double x)
{
	return sin(x-3)/4-(x-4)/2;
}

double f2_x(double x)
{
	return sin(x-3)/2+4;
}

double f2_p(double x)
{
	return cos(x)/4-(x-4)/2;
}
//***********************************f3*******************************
double f3(double x)
{
	return atan(x-6)/2+log(x)/3;
}
double f3_x(double x)
{
	return tan(-2*log(x)/3)+6;
}
double f3_p(double x)
{
	return 1/(2*(1+(x-6)*(x-6)))+1/(3*x);
}