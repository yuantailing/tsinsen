#include <math.h>
#include <iomanip>
#include <iostream>
using namespace std;
double SolveRoot(double (*pf)(double t), double a, double b, int n)
{
	double t, c;
	if (pf(a) > 0)
	{
		double t = a;
		a = b;
		b = t;
	}
	for (int i = 1; i < n; ++i)
	{
		c = (a + b) / 2;
		t = pf(c);
		if (t > 0)
			b = c;
		else
			a = c;
	}
	return (a + b) / 2;
}
double f(double x)
{
	return x * x - 2;
}
int main()
{
	cout << setprecision(10);
	for (int n = 1; n < 10; n += 1)
		cout << "SolveRoot(f,1,2," << n << ") = " <<setprecision(10)<< SolveRoot(f, 1, 2, n) << endl;
	cout << "The exact SolveRoot = " << setprecision(10) << sqrt((double)2) << endl;
	return 0;
}
