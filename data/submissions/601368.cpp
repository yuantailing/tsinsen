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

int fact[110];

int Fact(int x)
{
	if (fact[x]) return fact[x];
	else
	{
		fact[x]=(x*Fact(x-1))%9999;
		return fact[x];
	}
}

int by(int a, int b)
{
	return (a*b)%9999;
}

int byby(int x,int n)
{
	int ans=1;
	for (int i=0;i<n;i++)
		ans=(ans*x)%9999;
	return ans;
}

int plu(int a, int b)
{
	return (a+b)%9999;
}

int main()
{
	int n,x0;
	cin>>n>>x0;
	int a[110];
	for (int i=0;i<=n;i++)
		cin>>a[i];
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		sum=plu(sum,by(a[i],byby(x0,i-1)));
	}
	cout<<sum;
	system("pause");
	return 0;
}
