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
	int a[101];
	for (int i=0;i<n;i++)
		cin>>a[i];
	int count=0;
	for (int i=0;i<n;i++)
		for (int j=i;j<n;j++)
			if (a[i]>a[j])
				count++;
	cout<<count;
	//system("pause");
	return 0;
}
