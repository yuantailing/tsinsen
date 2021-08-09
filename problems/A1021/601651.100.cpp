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

int n,m;
int A[1001];
int B[1001];
int C[3000];

int cmp(const void *a, const void *b)
{
	if (*(int*)a>*(int*)b) return 1;
	if (*(int*)a==*(int*)b) return 0;
	return -1;
}


int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>A[i];
	cin>>m;
	for (int j=1;j<=m;j++)
		cin>>B[j];

	for (int i=1;i<=n;i++)
		C[i]=A[i];
	qsort(C+1,n,sizeof(int),cmp);
	int t=-0x7fffffff;
	for (int i=1;i<=n;i++)
	{
		bool ok=false;
		for (int j=1;j<=m;j++)
			if (B[j]==C[i])
				ok=true;
		if (ok&&C[i]>t)
		{
			t=C[i];
			cout<<C[i]<<' ';
		}
	}
	cout<<endl;

	for (int i=1;i<=n;i++)
		C[i]=A[i];
	for (int j=1;j<=m;j++)
		C[n+j]=B[j];
	qsort(C+1,m+n,sizeof(int),cmp);
	t=-0x7fffffff;
	for (int i=1;i<=m+n;i++)
	{
		if (C[i]>t)
		{
			t=C[i];
			cout<<C[i]<<' ';
		}
	}
	cout<<endl;

	for (int i=1;i<=n;i++)
		C[i]=A[i];
	qsort(C+1,n,sizeof(int),cmp);
	t=-0x7fffffff;
	for (int i=1;i<=n;i++)
	{
		bool ok=true;
		for (int j=1;j<=m;j++)
			if (B[j]==C[i])
				ok=false;
		if (ok&&C[i]>t)
		{
			t=C[i];
			cout<<C[i]<<' ';
		}
	}
	//cout<<endl;

	//system("pause");
	return 0;
}
