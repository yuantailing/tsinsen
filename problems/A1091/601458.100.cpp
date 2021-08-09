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

int n,m;
int a[40];

void Print()
{
	int i;
	for (i=1;i<m;i++)
		cout<<a[i]<<' ';
	cout<<a[i]<<endl;
}

void Try(int x)
{
	for (int i=a[x-1]+1;i<=n+x-m;i++)
	{
		a[x]=i;
		if (x==m)
			Print();
		else
			Try(x+1);
	}
}

int main()
{
	cin>>n>>m;
	Try(1);
	//system("pause");
	return 0;
}
