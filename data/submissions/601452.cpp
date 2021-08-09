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
	int a[100];
	int cost=0;
	int step=0;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	while (++step<n)
	{
		int min=0x7fffffff;
		int p,q;
		for (int i=0;i<n;i++)
			if (a[i])
				if (a[i]<min)
					min=a[p=i];
		min=0x7fffffff;
		for (int i=0;i<n;i++)
			if (a[i])
				if (i!=p)
					if (a[i]<min)
						min=a[q=i];
		a[p]=a[p]+a[q];
		cost+=a[p];
		a[q]=0;
	}
	cout<<cost;
	//system("pause");
	return 0;
}
