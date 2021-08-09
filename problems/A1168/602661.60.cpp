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
	cin>>m>>n;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	for (int step=3;step<m+n;step++)
	{
		for (int x1=1;x1<=n&&x1<=step-1;x1++)
			for (int x2=x1+1;x2<=n&&x2<=step-1;x2++)
			{
				int y1=step-x1;
				int y2=step-x2;
				if (y1>m||y2>m) continue;
				int f1=0,f2=0,f3=0,f4=0;
				if (x1>1&&y2>1)
					f1=h[step-1][x1-1][x2]  +a[x1][y1]+a[x2][y2];
				if (y2>1)
					f2=h[step-1][x1][x2]    +a[x1][y1]+a[x2][y2];
				if (x1>1)
					f3=h[step-1][x1-1][x2-1]+a[x1][y1]+a[x2][y2];
				if (x2-x1>1||step==3)
					f4=h[step-1][x1][x2-1]  +a[x1][y1]+a[x2][y2];
				int max=f1;
				if (f2>max) max=f2;
				if (f3>max) max=f3;
				if (f4>max) max=f4;
				h[step][x1][x2]=max;
			}
	}
	cout<<h[m+n-1][n-1][n];
	system("pause");
	return 0;
}
