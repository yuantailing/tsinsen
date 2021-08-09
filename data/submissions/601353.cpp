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

int f(int x)
{
	int buf=0;
	while (x%2==0)
	{
		x/=2;
		++buf;
	}
	return buf;
}

int main()
{
	int n;
	cin>>n;
	int a[20][20];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j];
	int ok[20];
	for (int i=0;i<n;i++)
	{
		int t=0;
		for (int j=0;j<n;j++)
			if (a[i][j]==1)
				t++;
		if (t*2>n) ok[i]=1;
		else ok[i]=0;
		if (ok[i])
			cout<<i+1<<' ';
	}
	//system("pause");
	return 0;
}
