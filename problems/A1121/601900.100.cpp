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

typedef int NUM [1000];

NUM a;
int N;

bool huiwen(NUM a)
{
	int dit=0;
	for (int i=0;i<1000;i++)
		if (a[i])
			dit=i;
	for (int i=0;i<=dit;i++)
		if (a[i]!=a[dit-i])
			return false;
	return true;
}

void dao(NUM dst, NUM res)
{
	memset(dst,0,sizeof(NUM));
	int dit=0;
	for (int i=0;i<1000;i++)
		if (res[i])
			dit=i;
	for (int i=0;i<=dit;i++)
		dst[i]=res[dit-i];
}

void myplus(NUM c, NUM a, NUM b)
{
	memset(c,0,sizeof(NUM));
	for (int i=0;i<1000;i++)
	{
		c[i]+=a[i]+b[i];
		while (c[i]>=N)
		{
			c[i]-=N;
			if (i<999)
				c[i+1]++;
		}
	}
}

void dengyu(NUM dst, NUM res)
{
	for (int i=0;i<1000;i++)
		dst[i]=res[i];
}

void print(NUM a)
{
	int dit=0;
	for (int i=0;i<1000;i++)
		if (a[i])
			dit=i;
	for (int i=0;i<=dit;i++)
		cout<<a[i];
}

int main()
{
	cin>>N;
	char m[800];
	cin>>m;
	NUM M;
	memset(M,0,sizeof(M));
	int len=strlen(m);
	for (int i=0;i<len;i++)
	{
		if (m[i]<='9')
			M[i]=m[i]-'0';
		else
			M[i]=m[i]-'A'+10;
	}
	int step=0;
	while (!huiwen(M)&&step<=30)
	{
		//print(M);
		//cout<<endl;
		NUM A;
		dao(A,M);
		NUM B;
		dengyu(B,M);
		myplus(M,A,B);
		step++;
	}
	if (step<=30)
		cout<<"STEP="<<step;
	else
		cout<<"Impossible!";
	//system("pause");
	return 0;
}
