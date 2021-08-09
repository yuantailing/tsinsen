#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

double getRoot(double (*f)(double), double a, double b)
{
	double p=(a+b)/2;
	double fp=f(p);
	if (fabs(fp)<1e-6)
		return p;
	else
	{
		double fa=f(a);
		if (fp*fa<0)
			return getRoot(f,a,p);
		else
			return getRoot(f,p,b);
	}
}
