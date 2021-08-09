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

char sa[10][20];
char sb[10][20];
int a[10],b[10];
char t[10][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

void trans()
{
	for (int i=1;i<=8;i++)
	{
		int t=0;
		while (sa[i][t])
		{
			if (sa[i][t]<'a')
				sa[i][t++]=sa[i][t]-'A'+'a';
			t++;
		}
		t=0;
		while (sb[i][t])
		{
			if (sb[i][t]<'a')
				sb[i][t]=sb[i][t]-'A'+'a';
			t++;
		}
		switch (sa[i][0])
		{
		case 'm':a[i]=1;break;
		case 'w':a[i]=3;break;
		case 'f':a[i]=5;break;
		case 't':a[i]=(sa[i][1]=='h'?4:2);break;
		case 's':a[i]=(sa[i][1]=='u'?7:6);break;
		}
		switch (sb[i][0])
		{
		case 'm':b[i]=1;break;
		case 'w':b[i]=3;break;
		case 'f':b[i]=5;break;
		case 't':b[i]=(sb[i][1]=='h'?4:2);break;
		case 's':b[i]=(sb[i][1]=='u'?7:6);break;
		}
	}
}

int main()
{
	for (int i=1;i<=8;i++)
		cin>>sa[i]>>sb[i];
	trans();
	for (int i=1;i<=7;i++)
	{
		bool ok=true;
		for (int j=1;j<=8;j++)
			if (((a[j]==i)+(b[j]!=i))!=1)
				ok=false;
		if (ok)
		{
			cout<<t[i];
			return 0;
		}
	}
	//system("pause");
	return 0;
}
