#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <fstream>
#include <algorithm>
using namespace std;

int a[10][10];
bool pa[10][10];
bool pb[10][10];
bool pc[4][4][10];

int q[10][10]=
{
	0,0,0,0,0,0,0,0,0,0,
	0,6,6,6,6,6,6,6,6,6,
	0,6,7,7,7,7,7,7,7,6,
	0,6,7,8,8,8,8,8,7,6,
	0,6,7,8,9,9,9,8,7,6,
	0,6,7,8,9,10,9,8,7,6,
	0,6,7,8,9,9,9,8,7,6,
	0,6,7,8,8,8,8,8,7,6,
	0,6,7,7,7,7,7,7,7,6,
	0,6,6,6,6,6,6,6,6,6
};

/*
void Print()
{
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=9;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	//system("pause");
}
*/

int Maxn=-1;
void Check()
{
	int sum=0;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			sum+=a[i][j]*q[i][j];
	if (sum>Maxn)
		Maxn=sum;
}

void Try(int x, int y)
{
	if (x==10) Check();
	else if (y==10) Try(x+1,1);
	else if (a[x][y]!=0)
		Try(x,y+1);
	else
	{
		int t;
		for (t=1;t<=9;t++)
		{
			if (pa[x][t]||pb[y][t]||pc[(x+2)/3][(y+2)/3][t]) continue;
			pa[x][t]=pb[y][t]=pc[(x+2)/3][(y+2)/3][t]=true;
			a[x][y]=t;
			Try(x,y+1);
			a[x][y]=0;
			pa[x][t]=pb[y][t]=pc[(x+2)/3][(y+2)/3][t]=false;
		}
	}
}

void Update()
{
	for (int x=1;x<=9;x++)
		for (int y=1;y<=9;y++)
		{
			int t=a[x][y];
			if (t>0)
				pa[x][t]=pb[y][t]=pc[(x+2)/3][(y+2)/3][t]=true;
		}
}

int main()
{
	memset(pa,0,sizeof(pa));
	memset(pb,0,sizeof(pb));
	memset(pc,0,sizeof(pc));
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			cin>>a[i][j];
	Update();
	Try(1,1);
	cout<<Maxn;
	//system("pause");
	return 0;
}
