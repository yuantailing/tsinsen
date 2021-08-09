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

int shanga[30];
int xiaa[30];
int shangb[30];
int xiab[30];

int main()
{
	shanga[1]=1;
	shangb[2]=1;
	xiab[2]=1;
	for (int i=3;i<30;i++)
	{
		shanga[i]=shanga[i-1]+shanga[i-2];
		shangb[i]=shangb[i-1]+shangb[i-2];
		xiaa[i]=shanga[i-1];
		xiab[i]=xiab[i-1];
	}
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	int na=0;
	int nb=0;
	int xa=0;
	int xb=0;
	for (int i=1;i<5;i++)
	{
		if (i<=n)
		{
			na=na+shanga[i]-xiaa[i];
			nb=nb+shangb[i]-xiab[i];
		}
		if (i<=x)
		{
			xa=xa+shanga[i]-xiaa[i];
			xb=xb+shangb[i]-xiab[i];
		}
	}
	if (nb==0)
	{
		cout<<a*xa;
		return 0;
	}
	int b=(m-a*na)/nb;
	cout<<a*xa+b*xb;
	//system("pause");
	return 0;
}
