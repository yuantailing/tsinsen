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

char p[111];
char q[111];
char m[111];
char d[128];

int main()
{
	cin>>p;
	cin>>q;
	cin>>m;
	for (int i=0;q[i];i++)
	{
		if (d[q[i]])
		{
			if (d[q[i]]!=p[i])
			{
				cout<<"Failed";
				return 0;
			}
		}
		else
		{
			d[q[i]]=p[i];
		}
	}
	for (char i='A';i<='Z';i++)
	{
		if (!d[i])
		{
			cout<<"Failed";
			return 0;
		}
		bool ok=false;
		for (char j='A';j<='Z';j++)
		{
			if (d[i]==j)
				ok=true;
		}
		if (!ok)
		{
			cout<<"Failed";
			return 0;
		}
	}
	for (int i=0;m[i];i++)
	{
		for (char j='A';j<='Z';j++)
		{
			if (d[j]==m[i])
				cout<<j;
		}
	}
	//system("pause");
	return 0;
}
