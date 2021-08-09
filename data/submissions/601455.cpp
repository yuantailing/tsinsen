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

int a[10000];

int main()
{
	int n;
	cin>>n;
	a[1]=1;
	int i;
	for (i=1;i<=n;i++)
	{
		for (int j=1;j<1000;j++)
			a[j]*=i;
		for (int j=1;j<1000;j++)
			while (a[j]>=10000)
			{
				a[j]-=10000;
				a[j+1]++;
			}
	}
	i=2000;
	while (!a[i]) i--;
	printf("%d",a[i--]);
	while (i>=1) printf("%04d",a[i--]);
	//system("pause");
	return 0;
}
