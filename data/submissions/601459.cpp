#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

double a,b,c,d;
double z;

double f(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}

double g(double x)
{
	return 3*a*x*x+2*b*x+c;
}

int main()
{
	cin>>a>>b>>c>>d;
	cin>>z;
	int times=1;
	double fz=f(z);
	while (fabs(fz)>1e-7)
	{
		z-=f(z)/g(z);
		fz=f(z);
		times++;
	}
	printf("%.3lf %d",z,times);
	//system("pause");
	return 0;
}
