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

int Mod(int x)
{
	if (x>=0) return x%9999;
	else return -((-x)%9999);
}

int Fact(int x)
{
	if (fact[x]) return fact[x];
	else
	{
		fact[x]=Mod((x*Fact(x-1)));
		return fact[x];
	}
}

int by(int a, int b)
{
	return Mod(a*b);
}

int byby(int x,int n)
{
	int ans=1;
	for (int i=0;i<n;i++)
		ans=Mod((ans*x));
	return ans;
}

int plu(int a, int b)
{
	return Mod(a+b);
}

int main()
{
	int n,x0;
	cin>>n;
	if (n==0)
	{
		cout<<"0";
		return 0;
	}
	cin>>x0;
	int a[110];
	for (int i=0;i<=n;i++)
		cin>>a[i];
	int sum=0;
	for (int i=1;i<=n;i++)
	{
		sum=plu(sum,by(a[i],by(i,byby(x0,i-1))));
	}
	cout<<sum;
	//system("pause");
	return 0;
}
