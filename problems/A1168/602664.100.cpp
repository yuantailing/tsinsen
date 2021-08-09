#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>
#include <cstdarg>
using namespace std;

int m,n;
int a[51][51];

int h[101][51][51];

int main()
{
	//freopen("message.in","r",stdin);
	//freopen("message.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int y1,y2,f1,f2,f3,f4,max;
	for (int step=3;step<m+n;step++)
	{
		for (int x1=1;x1<=n;x1++)
		{
			y1=step-x1;
			if (y1<=m)
			for (int x2=x1+1;x2<=n;x2++)
			{
				y2=step-x2;
				if (y2<1)
					continue;
				f1=h[step-1][x1-1][x2];
				f2=h[step-1][x1][x2];
				f3=h[step-1][x1-1][x2-1];
				f4=h[step-1][x1][x2-1];
				max=f1;
				if (f2>max) max=f2;
				if (f3>max) max=f3;
				if (f4>max) max=f4;
				h[step][x1][x2]=max+a[y1][x1]+a[y2][x2];
			}
		}
	}
	cout<<h[m+n-1][n-1][n];
	//system("pause");
	return 0;
}
