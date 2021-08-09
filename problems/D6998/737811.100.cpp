#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long mat[40][40];

int n,m;

void by(mat a, mat b, mat c)//c=a*b
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			c[i][j]=0;
			for (int k=0;k<n;k++)
				c[i][j]+=a[i][k]*b[k][j];
		}
}

int main()
{
	cin>>n>>m;
	mat a,b,c;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>a[i][j];
	memset(b,0,sizeof(b));
	for (int i=0;i<n;i++)
		b[i][i]=1;
	memcpy(c,b,sizeof(mat));
	for (int i=1;i<=m;i++)
	{
		by(a,b,c);
		memcpy(b,c,sizeof(mat));
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<<c[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
