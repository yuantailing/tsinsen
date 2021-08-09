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

int x,y;
int d;

void Turn()
{
	if (d==4) d=1;
	else d++;
}

void Next()
{
	switch(d)
	{
	case 1:
		x++;break;
	case 2:
		y++;break;
	case 3:
		x--;break;
	case 4:
		y--;break;
	}
}

void Forword()
{
	switch(d)
	{
	case 1:
		x--;break;
	case 2:
		y--;break;
	case 3:
		x++;break;
	case 4:
		y++;break;
	}
}

int main()
{
	int m,n;
	cin>>m>>n;
	int a[222][222];
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	int b[222][222];
	memset(b,0,sizeof(b));
	for (int i=0;i<222;i++)
		b[i][0]=b[0][i]=b[m+1][i]=b[i][n+1]=1;
	x=y=1;
	d=1;
	while (b[x][y]==0)
	{
		b[x][y]=1;
		cout<<a[x][y]<<' ';
		Next();
		if (b[x][y])
		{
			Forword();
			Turn();
			Next();
		}
	}
	//system("pause");
	return 0;
}
