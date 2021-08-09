#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

int isNumber(char c)
{
	if (c>='0'&&c<='0') return 1;
	return 0;
}

int main()
{
	int n,m;
	cin>>n>>m;
	int a[60][110];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			cin>>a[i][j];
	for (int i=0;i<m;i++)
	{
		int p;
		p=n-1;
		for (int j=n-2;j>=0;j--)
			if (a[j][i])
				if ((a[j][i]<a[p][i])||(!a[p][i]))
					p=j;
		if (!a[p][i]) cout<<"0 ";
		else cout<<p+1<<' ';
	}
	//system("pause");
	return 0;
}
