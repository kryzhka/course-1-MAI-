double eps = 0.0000001;
double dabs(double x) { 
	return (x > 0 ? x : -x);
}

double dichotomy(double f(double), double a, double b) {
	double prevX = b, x = (a + b) / 2.;
	while(dabs(prevX - x) > eps) {
		if(f(x)*f(a) > 0)
			a = x;
		else
			b = x;
		prevX = x;
		x = (a + b) / 2.;
	}
	return x;
}
double iteration(double f(double), double a, double b) {
	double prevX = (a+b)/2., x = f(prevX);
	while(dabs(x-prevX) > eps) {
		prevX = x;
		x = f(x);
	}
	return x;
}
double tangent(double f(double), double F(double), double a, double b) {
	double prevX = (a+b/2.), x = prevX - f(prevX)/F(prevX);
	while(dabs(prevX - x) > eps) {
		prevX = x;
		x = prevX - f(prevX)/F(prevX);
	}
	return x;
}
double chord(double f(double), double a, double b) {
	double prevX = b, ya = f(a), yb = f(b);
	double x = (ya*b-yb*a)/(ya-yb);
	while(dabs(prevX - x) > eps) {
		if(ya*f(x) > 0)
			a = x;
		else
			b = x;
		ya = f(a), yb = f(b);
		prevX = x;
		x = (ya*b-yb*a)/(ya-yb);
	}
	return x;
}