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

double a[4],b[4];
double d[200];

double h(int x)
{
	double sum=0;
	for (int i=0;i<4;i++)
	{
		if (i-x>=0&&i-x<4)
			sum+=a[i]*b[i-x];
	}
	return sum;
}

int main()
{
	
	int Q1,Q2,Q3;
	for (int i=0;i<4;i++)
		cin>>a[i];
	for (int i=0;i<4;i++)
		cin>>b[i];
	d[100]=1.0;
	for (int i=0;i<12;i++)
	{
		double dd[200];
		memcpy(dd,d,sizeof(d));
		for (int j=10;j<190;j++)
		{
			d[j]=0;
			for (int k=-3;k<=3;k++)
				d[j]+=dd[j-k]*h(k);
		}
	}
	cin>>Q1>>Q2>>Q3;
	printf("%d%%\n",(int)(d[100+Q1]*100+0.5));
	printf("%d%%\n",(int)(d[100+Q2]*100+0.5));
	printf("%d%%\n",(int)(d[100+Q3]*100+0.5));

	//system("pause");
	return 0;
}
