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
	int n;
	cin>>n;
	int a[40];
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int s=0;
	while (n>0)
	{
		s+=a[n];
		for (int j=1;j<n;j++)
			a[j]=a[j+1]-a[j];
		n--;
	}
	cout<<s;
	//system("pause");
	return 0;
}
