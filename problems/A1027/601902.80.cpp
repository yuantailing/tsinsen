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

bool similar(char *aa, char *bb)
{
	char a[200],b[200];
	strcpy(a,aa);
	strcpy(b,bb);
	if (strcmp(a,b)==0)
		return true;
	int t=0;
	while (a[t]==b[t])
		t++;
	if (!a[t])
	{
		if (!b[t+1])
			return true;
		else
			return false;
	}
	if (!b[t])
	{
		if (!a[t+1])
			return true;
		else
			return false;
	}
	if (strlen(a)==strlen(b))
	{
		if (strcmp(a+t+1,b+t+1)==0)
			return true;
		else
			return false;
	}
	int lena=strlen(a);
	int lenb=strlen(b);
	if (a>b)
	{
		if (strcmp(a+t+1,b+t)==0)
			return true;
		else
			return false;
	}
	else
	{
		if (strcmp(a+t,b+t+1)==0)
			return true;
		else
			return false;
	}
}

int main()
{
	char aim[30];
	int N;
	char words[200][30];
	char vocabulary[30];
	cin>>aim;
	cin>>N;
	int i;
	for (i=0;i<N;i++)
	{
		cin>>vocabulary;
		if (similar(aim,vocabulary))
		{
			cout<<vocabulary;
			break;
		}
	}
	if (i>=N)
		cout<<"NOANSWER";
	//system("pause");
	return 0;
}
