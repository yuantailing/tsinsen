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

int n;
int ok[10][10];
int ans;
int a[10][10];

int b1[20],b2[20],b3[20];
int w1[20],w2[20],w3[20];

void Try(int x)
{
	if (x<=n)
	{
		for (int i=1;i<=n;i++)
			if (ok[x][i]&&(!b1[i])&&(!b2[i+x])&&(!b3[10+x-i]))
			{
				ok[x][i]=0;
				b1[i]=b2[i+x]=b3[10+x-i]=1;
				Try(x+1);
				ok[x][i]=1;
				b1[i]=b2[i+x]=b3[10+x-i]=0;
			}
	}
	else if (x<=n+n)
	{
		x-=n;
		for (int i=1;i<=n;i++)
			if (ok[x][i]&&(!w1[i])&&(!w2[i+x])&&(!w3[10+x-i]))
			{
				ok[x][i]=0;
				w1[i]=w2[i+x]=w3[10+x-i]=1;
				Try(x+n+1);
				ok[x][i]=1;
				w1[i]=w2[i+x]=w3[10+x-i]=0;
			}
	}
	else
		ans++;
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>ok[i][j];
	Try(1);
	cout<<ans;
	//system("pause");
	return 0;
}
