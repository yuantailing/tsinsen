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

double dis,C,per,p0;
double p[10000];
double d[10000];
int N;
const double eps=0.01;

void Failed()
{
	cout<<"No Solution";
	exit(0);
}

int main()
{
	cin>>dis>>C>>per>>p[0]>>N;
	d[0]=0;
	for (int i=1;i<=N;i++)
		cin>>d[i]>>p[i];
	d[N+1]=dis;
	p[N+1]=0;
	double farest=C*per;//const
	double cost=0;
	double remain=0;
	for (int i=0;i<=N;i++)
	{
		if (i>0)
		{
			remain=remain-(d[i]-d[i-1])/per;
			if (remain+eps<0)
				Failed();
		}
		bool havecheaper=false;
		int j;
		for (j=i+1;j<=N+1&&d[j]-d[i]<=farest;j++)
			if (p[j]<p[i])
			{
				havecheaper=true;
				break;
			}
		if (havecheaper)
		{
			if (remain*per>=d[j]-d[i])
			{
			}
			else
			{
				cost=cost+((d[j]-d[i])/per-remain)*p[i];
				remain=(d[j]-d[i])/per;
			}
		}
		else
		{
			cost=cost+(C-remain)*p[i];
			remain=C;
		}
	}
	remain=remain-(d[N+1]-d[N])/per;
	if (remain+eps<0)
		Failed();
	printf("%.2f",cost);
	//system("pause");
	return 0;
}
