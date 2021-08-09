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
	int n,m;
	cin>>n>>m;
	int s[4000];
	for (int i=1;i<=n;i++)
		s[i]=i;
	for (int i=1;i<=m;i++)
	{
		int p,q;
		cin>>p>>q;
		for (int j=1;j<=n;j++)
			if (s[j]==s[q]) s[j]=s[p];
	}
	int stack[4000];
	int top=0;
	for (int i=1;i<=n;i++)
	{
		int t=0;
		for (int j=1;j<=top;j++)
			if (s[i]==stack[j])
			{
				t=1;
				break;
			}
		if (t==0)
			stack[++top]=i;
	}
	cout<<top;
	//system("pause");
	return 0;
}
