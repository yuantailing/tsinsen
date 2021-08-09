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

int main()
{
	int m;
	int a[5];
	for (m=0;m<=5*25*25;m++)
	{
		a[0]=(m/1)%5+1;
		a[1]=(m/5)%5+1;
		a[2]=(m/25)%5+1;
		a[3]=(m/125)%5+1;
		a[4]=(m/625)%5+1;
		if (a[4]==2||a[4]==3) continue;
		if (a[0]*a[1]*a[2]*a[3]*a[4]!=120||a[0]+a[1]+a[2]+a[3]+a[4]!=15) continue;
		bool p[5];
		p[0]=(a[4]==1);
		p[1]=(a[1]==2);
		p[2]=(a[0]==5);
		p[3]=(a[2]!=1);
		p[4]=(a[3]==1);
		if ((p[0]+p[1]+p[2]+p[3]+p[4])!=2) continue;
		int i,j;
		for (i=0;i<4;i++)
			if (p[i]) break;
		for (j=i+1;j<=4;j++)
			if (p[j]) break;
		if (a[i]+a[j]==3)
		{
			for (int k=0;k<=4;k++)
				cout<<a[k]<<' ';
		}
	}
	//system("pause");
	return 0;
}
