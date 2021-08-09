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
	int n=0;
	int s[10000];
	int m[10000];
	int top=-1;
	int last=-1;
	int max=0;
	int count=0;
	memset(m,0,sizeof(m));
	while (scanf("%d",&s[++top])==1)
	{
		if (s[top]>last)
			n++;
		last=s[top];
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
	cout<<max<<endl;
	cout<<n;
	//system("pause");
	return 0;
}
