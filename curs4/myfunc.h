
double epsilon = 0.0000001;
//***********************************f1*******************************
double f1(double x)
{
	return 3*x-14+pow(exp(1.),x)-pow(exp(1.),-x);
}

double f1_x(double x)
{
	return log(-3*x+14+pow(exp(1.),-x));
}

double f1_p(double x)
{
	return 3+2*pow(exp(1.),x);
}
//***********************************f2*******************************
double f2(double x)
{
	return sin(x)-atan(x-3)/2-x;
}

double f2_x(double x)
{
	return sin(x)-atan(x-3)/2;
}

double f2_p(double x)
{
	return cos(x)+1/2*(1+(x-3)*(x-3))-1;
}
//***********************************f3*******************************
double f3(double x)
{
	return sin(x-1)-log(x);
}
double f3_x(double x)
{
	return pow(exp(1.),sin(x-1));
}
double f3_p(double x)
{
	return cos(x-1)-1/x;
}
//*****************************obrabotka******************************
double dixotomiya(double f(double),double a, double b)
{
	double half=0;
	while(abs(a-b)>epsilon)
	{
	if(f(a)*f(half)>0)
		a=half;
	else
		b=half;
	half=(a+b)/2;
	}
	return half;
}

double iteration(double f(double), double a, double b)
{

	double x, x_old;
	x_old=(a+b)/2;
	x=f(x_old);
	while(abs(x_old-x)>epsilon)
	{
		x_old=x;
		x=f(x);
	}
	return x;
}

double newton(double f(double),double f_p(double), double a, double b)
{
	double x, x_old;
	x_old=(a+b)/2;
	x=x_old-f(x_old)/f_p(x_old);
	while(abs(x_old-x)>epsilon)
	{
		x_old=x;
		x=x_old-f(x_old)/f_p(x_old);
	}
	return x;
}

double segment(double f(double), double a, double b)
{
	double x_old=b;
	double f_a=f(a);
	double f_b=f(b);
	double x=(f_a*b-f_b*a)/(f_a-f_b);
	while (abs(x-x_old)>epsilon)
	{
		if(f_a*f(x)>0)
			a=x;
		else
			b=x;
		f_a=f(a),f_b=f(b);
		x_old=x;
		x=(f_a*b-f_b*a)/(f_a-f_b);
	}
	return x;
}