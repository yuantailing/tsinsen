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

int A(int x, int k)
{
	int a=1;
	for (int i=0;i<k;i++)
		a*=x--;
	return a;
}

int main()
{
	int k,n;
	cin>>k>>n;
	int a[101],b[101];
	for (int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	printf("f");
	for (int i=0;i<k;i++)
		printf("'");
	printf("(x)=");
	for (int i=0;i<n;i++)
	{
		int zhishu=b[i]-k;
		if (zhishu<0) continue;
		int xishu=a[i]*A(b[i],k);
		if (i!=0)
			if (xishu>0)
				printf("+");

		if (zhishu==1)
			printf("%d*x",xishu);
		else if (zhishu==0)
			printf("%d",xishu);
		else
			printf("%d*x^%d",xishu,b[i]-k);
	}
	//system("pause");
	return 0;
}
