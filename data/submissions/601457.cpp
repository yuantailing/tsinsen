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

int k;
int a[30];
int used[30];
int ans;

bool Judge(int n)
{
	for (int i=3;i<=n;i++)
	{
		if (a[i-1]>a[i-2])
		{
			if (a[i]>=a[i-2])
				return false;
		}
		else
		{
			if (a[i]<=a[i-2])
				return false;
		}
	}
	return true;
}

void Print(int n)
{
	for (int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}

void Try(int n)
{
	for (int i=1;i<=k;i++)
		if (!used[i])
		{
			a[n]=i;
			used[i]=1;
			if (Judge(n))
			{
				ans++;
				Try(n+1);
			}
			a[n]=0;
			used[i]=0;
		}
}

int main()
{
	cin>>k;
	Try(1);
	cout<<ans-k;
	//system("pause");
	return 0;
}
