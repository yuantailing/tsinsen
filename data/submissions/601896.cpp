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

int cmp(const void *a, const void *b)
{
	if (*(int*)a>*(int*)b) return 1;
	if (*(int*)a==*(int*)b) return 0;
	return -1;
}

int main()
{
	int n=0;
	int buf;
	int s[10000];
	int m[10000];
	int top=-1;
	int max=0;
	int count=0;
	int base[10000];
	int base_top=-1;
	memset(base,0,sizeof(base));
	for (int i=0;i<10000;i++)
		m[i]=1;
	while (scanf("%d",&buf)==1)
	{
		s[++top]=buf;
	}
	for (int i=top;i>=0;i--)
	{
		for (int j=i+1;j<=top;j++)
			if (s[j]<=s[i])
				if (m[i]<m[j]+1)
					m[i]=m[j]+1;
		if (m[i]>max)
			max=m[i];
	}
	for (int i=0;i<=top;i++)
	{
		if (base_top>0)
			qsort(base,base_top+1,sizeof(int),cmp);
		int j;
		for (j=0;j<=base_top;j++)
			if (base[j]>=s[i])
			{
				base[j]=s[i];
				break;
			}
		if (j>base_top)
			base[++base_top]=s[i];
	}
	n=base_top+1;
	cout<<max<<endl<<n;
	//system("pause");
	return 0;
}
