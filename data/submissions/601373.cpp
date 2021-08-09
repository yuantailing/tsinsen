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

double adjust(double v, double t, double T)
{
	int f=(int)(t/T);
	if (f>9)
		return v*0.1;
	else
		return v-v*0.1*f;
}

double tRemain(double t, double T)
{
	int f=(int)(t/T);
	return (T*(f+1))-t;
}

int main()
{
	int n;
	double t;
	cin>>n>>t;
	double Vt[5];
	double Vr[5];
	for (int i=1;i<=4;i++)
		cin>>Vt[i];
	for (int i=1;i<=4;i++)
		cin>>Vr[i];
	int T[1001];
	double L[1001];
	for (int i=1;i<=n;i++)
		cin>>T[i]>>L[i];
	
	double V[5];
	memcpy(V,Vt,sizeof(Vt));
	int jieduan=0;
	double time=0;
	while ((++jieduan)<=n)
	{
		double v0;
		v0=V[T[jieduan]];
		double v=adjust(v0,time,t);
		double l;
		l=L[jieduan];
		while (1)
		{
			if (l>v*tRemain(time,t))
			{
				l-=v*tRemain(time,t);
				if (v>v0*0.15)
					v-=v0*0.1;
				time+=tRemain(time,t);
			}
			else
			{
				time+=(l/v);
				l=0;
				break;
			}
		}
	}
	double time_wugui=time;

	memcpy(V,Vr,sizeof(Vt));
	jieduan=0;
	time=0;
	while ((++jieduan)<=n)
	{
		double v0;
		v0=V[T[jieduan]];
		double v=adjust(v0,time,t);
		double l;
		l=L[jieduan];
		while (1)
		{
			if (l>v*tRemain(time,t))
			{
				l-=v*tRemain(time,t);
				if (v>v0*0.15)
					v-=v0*0.1;
				time+=tRemain(time,t);
			}
			else
			{
				time+=(l/v);
				l=0;
				break;
			}
		}
	}
	double time_tuzi=time;

	if (fabs(time_tuzi-time_wugui)<0.001)
		printf("D\n%.2lf",time_tuzi);
	else if (time_tuzi<time_wugui)
		printf("R\n%.2lf",time_tuzi);
	else if (time_tuzi>time_wugui)
		printf("T\n%.2lf",time_wugui);


	//system("pause");
	return 0;
}
