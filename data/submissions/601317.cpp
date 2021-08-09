#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

long long int f(int x)
{
	static long long int a[10010];
	a[1]=a[2]=1;
	if (a[x]) return a[x];
	else
	{
		a[x]=f(x-1)+f(x-2);
		return a[x];
	}
}

int main()
{
	int s,t;
	cin>>s>>t;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	for (int i=s;i<=t;i++)
	{
		long long int y=f(i);
		if ((y%a)&&(y%b)&&(y%c)&(y%d))
			cout<<i<<' ';
	}
	system("pause");
	return 0;
}
