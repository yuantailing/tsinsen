#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <fstream>
using namespace std;

int prime[5500];
int prime_top=-1;
bool _Prime(int x)
{
	if (x<2) return false;
	if (x==2) return true;
	if (x%2==0) return false;
	int t=sqrt(x+1);
	for (int i=3;i<=t;i+=2)
		if (x%i==0)
			return false;
	return true;
}

class FACT{
public:
	int x;
	int n;
};

void showFACTstack(FACT*s, int stacktop)
{
	for (int i=0;i<=stacktop;i++)
		printf("s[%d]: %d ^ %d\n",i,s[i].x,s[i].n);
}

int main()
{
	//freopen("son.in", "r", stdin);
	//freopen("son.out", "w", stdout);

	//预生成质数表
	for (int i=2;i<=50000;i++)
		if (_Prime(i))
			prime[++prime_top]=i;

	int n;
	cin>>n;
	for (int ___I = 0; ___I < n; ___I ++)
	{
		int a0, a1, b0, b1;
		cin>>a0>>a1>>b0>>b1;
		int a2=a0/a1;
		int b2=b1/b0;

		int b1copy=b1;
		int minprimepos=0;
		int thisprime;
		int ans=1;
		while (b1copy>1)
		{
			//分解b1
			int thisprime = prime[minprimepos]*prime[minprimepos]<=b1copy ? prime[minprimepos] : b1copy;
			bool have=false;
			while (b1copy%thisprime==0)
			{
				have=true;
				b1copy/=thisprime;
			}
			minprimepos++;
			if (!have)
				continue;
			
			//计算有多少种x
			int factnumber=thisprime;
			int minbecauseofa1=0;
			while (a1%factnumber==0)
			{
				minbecauseofa1++;
				a1/=factnumber;
			}
			bool morebecauseofa2=(a2%factnumber!=0);
			int countfactofb0=0;
			while (b0%factnumber==0)
			{
				countfactofb0++;
				b0/=factnumber;
			}
			int morebecauseofb2=0;
			while (b2%factnumber==0)
			{
				morebecauseofb2++;
				b2/=factnumber;
			}
			int Min=minbecauseofa1;
			int Max=countfactofb0+morebecauseofb2;
			if (morebecauseofb2>0)
			{
				if (Min<Max&&!morebecauseofa2)
				{
					ans=0;
					break;
				}
				else
					Min=Min<Max?Max:Min;
			}
			if (!morebecauseofa2)
				Max=Max>Min?Min:Max;
			if (Min>Max)
			{
				ans=0;
				break;
			}
			else
				ans*=(Max-Min+1);
		}
		cout<<ans<<endl;
	}

	//system("pause");
	return 0;
}
