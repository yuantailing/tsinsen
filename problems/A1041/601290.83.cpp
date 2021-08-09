#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

typedef int mat[40][40];

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
	memcpy(b,a,sizeof(mat));
	memcpy(c,a,sizeof(mat));
	for (int i=2;i<=m;i++)
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
	system("pause");
	return 0;
}
