#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

int ma[10010];
int mb[10010];
int mc[10010];
int md[10010];

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
	ma[1]=ma[2]=1%a;
	mb[1]=mb[2]=1%b;
	mc[1]=mc[2]=1%c;
	md[1]=md[2]=1%d;
	for (int i=3;i<=10000;i++)
	{
		ma[i]=(ma[i-1]+ma[i-2])%a;
		mb[i]=(mb[i-1]+mb[i-2])%b;
		mc[i]=(mc[i-1]+mc[i-2])%c;
		md[i]=(md[i-1]+md[i-2])%d;
	}
	for (int i=s;i<=t;i++)
		if (ma[i]&&mb[i]&&mc[i]&&md[i])
			cout<<i<<' ';
	//system("pause");
	return 0;
}
