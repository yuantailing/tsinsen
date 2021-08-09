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

int a[20][20];
bool used[400];
bool prime[400];
int n;

bool _Prime(int x)
{
	for (int i=2;i<x;i++)
		if (x%i==0)
			return false;
	return true;
}

void EndThis()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	//system("pause");
	exit(0);
}

void Try(int x, int y)
{
	if (x>n)
		EndThis();
	int nn=n*n;
	for (int i=1;i<=nn;i++)
	if (!used[i])
	{
		bool ok=true;
		if (x>1&&(!prime[a[x-1][y]+i])) ok=false;
		if (y>1&&(!prime[a[x][y-1]+i])) ok=false;
		if (!ok) continue;
		a[x][y]=i;
		used[i]=true;
		if (y==n) Try(x+1,1);
		else Try(x,y+1);
		a[x][y]=0;
		used[i]=false;
	}
}


int main()
{
	for (int i=2;i<400;i++)
		prime[i]=_Prime(i);
	a[1][1]=1;
	used[1]=true;
	cin>>n;
	Try(1,2);
	cout<<"NO";
	//system("pause");
	return 0;
}
