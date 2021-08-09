#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int main()
{
	double x[5],y[5];
	for (int i=1;i<=4;i++)
		cin>>x[i]>>y[i];
	double max1x=Max(x[1],x[2]),min1x=x[1]+x[2]-max1x;
	double max2x=Max(x[3],x[4]),min2x=x[3]+x[4]-max2x;
	double max1y=Max(y[1],y[2]),min1y=y[1]+y[2]-max1y;
	double max2y=Max(y[3],y[4]),min2y=y[3]+y[4]-max2y;
	double p1x=Max(min1x,min2x);
	double p1y=Max(min1y,min2y);
	double p2x=Min(max1x,max2x);
	double p2y=Min(max1y,max2y);
	if (p1x>p2x||p1y>p2y)
		cout<<"0.00";
	else
		cout<<setiosflags(ios_base::fixed)<<setprecision(2)<<(p2x-p1x)*(p2y-p1y);
	//system("pause");
	return 0;
}
