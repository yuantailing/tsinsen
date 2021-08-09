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

long long int m,n,p;
long long int num;

long long p10[19];
long long pn[19];
long long pp[19];


long long pow(int x, int y)
{
	long long ans=1;
	for (int i=0;i<y;i++)
		ans*=x;
	return ans;
}

int main()
{
	scanf("%d<%d>%d",&m,&n,&p);
	p10[0]=pn[0]=pp[0]=1;
	for (int i=1;i<19;i++)
	{
		p10[i]=10*p10[i-1];
		pn[i]=n*pn[i-1];
		pp[i]=p*pp[i-1];
	}
	for (int i=0;i<19;i++)
	{
		num+=((m/p10[i])%10)*pn[i];
	}
	cout<<m<<'<'<<n<<'>'<<'=';
	bool start=false;
	for (int i=18;i>=0;i--)
	{
		int dit=(num/pp[i])%p;
		if (dit)
			start=true;
		if (start)
		{
			cout<<dit;
		}
	}
	cout<<'<'<<p<<'>';
	//system("pause");
	return 0;
}
