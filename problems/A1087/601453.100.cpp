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

int main()
{
	char a[101],b[101];
	char aa[201],bb[201];
	char cc[201];
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	cin>>a>>b;
	int i;
	for (i=0;a[i];i++)
		a[i]-='0';
	int tail=200;
	while (--i>=0) aa[tail--]=a[i];

	for (i=0;b[i];i++)
		b[i]-='0';
	tail=200;
	while (--i>=0) bb[tail--]=b[i];
	
	for (i=200;i>=0;i--)
	{
		cc[i]=aa[i]+bb[i];
		while (cc[i]>=10)
		{
			cc[i]-=10;
			aa[i-1]++;
		}
	}

	i=0;
	while (!cc[i]) i++;

	while (i<=200) cout<<(int)cc[i++];

	//system("pause");
	return 0;
}
