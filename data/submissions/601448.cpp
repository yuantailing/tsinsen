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

typedef struct{
	double real;
	double img;
}COMPLEX;

double const pi=3.1415926535897932384626;
int n;
COMPLEX x[16390];
COMPLEX w[16384];
COMPLEX fy[16384];

void By(COMPLEX &c, COMPLEX &a, COMPLEX &b)
{
	double d=a.real*b.real-a.img*b.img;
	c.img=a.real*b.img+a.img*b.real;
	c.real=d;
}

void Add(COMPLEX &c, COMPLEX &a, COMPLEX &b)
{
	double d=a.real+b.real;
	c.img=a.img+b.img;
	c.real=d;
}

void Print(COMPLEX &c)
{
	printf("%.2lf %.2lf\n",c.real/n,c.img/n);
}

int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>x[i].real>>x[i].img;
	COMPLEX one={1.0,0.0};
	w[0]=one;
	w[1].real=cos(2*pi/n);
	w[1].img=sin(2*pi/n);
	for (int i=2;i<n;i++)
	{
		By(w[i],w[i-1],w[1]);
	}
	for (int i=0;i<n;i++)
	{
		By(fy[i],w[i],w[i]);
	}
	COMPLEX tmp=one;
	COMPLEX fyji[17000];
	for (int i=0;i<n;i++)
		fyji[i]=one;
	for (int i=0;i<n;i++)
	{
		COMPLEX Y={0,0},p={0,0},q={0,0};
		for (int j=0;j<=n/2-1;j++)
		{
			By(tmp,x[j*2],fyji[j]);
			Add(p,p,tmp);
			By(tmp,x[j*2+1],fyji[j]);
			Add(q,q,tmp);
		}
		for (int j=0;j<=n/2-1;j++)
			By(fyji[j],fyji[j],fy[j]);
		By(q,q,w[i]);
		Add(Y,q,p);
		Print(Y);
	}
	//system("pause");
	return 0;
}
