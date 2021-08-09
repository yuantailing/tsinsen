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
int remaina[30];
int remainb[30];

int main()
{
	shanga[1]=1;
	shangb[2]=1;
	xiab[2]=1;
	remaina[1]=1;
	remaina[2]=1;
	for (int i=3;i<30;i++)
	{
		shanga[i]=shanga[i-1]+shanga[i-2];
		shangb[i]=shangb[i-1]+shangb[i-2];
		xiaa[i]=shanga[i-1];
		xiab[i]=shangb[i-1];
		remaina[i]=remaina[i-1]+shanga[i]-xiaa[i];
		remainb[i]=remainb[i-1]+shangb[i]-xiab[i];
		printf("<%d>%da+%db\n",i,remaina[i],remainb[i]);
	}
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	int na=remaina[n-1];
	int nb=remainb[n-1];
	int xa=remaina[x];
	int xb=remainb[x];
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
