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

int w[7]={0,1,2,3,5,10,20};
int v[1001];

int main()
{
	v[0]=1;
	for (int i=1;i<=6;i++)
	{
		int n;
		cin>>n;
		for (int j=1000;j>=0;j--)
			if (v[j])
			{
				for (int k=1;k<=n;k++)
					v[j+k*w[i]]=1;
			}
	}
	int N=0;
	for (int j=1;j<=1000;j++)
		if (v[j])
			N++;

	cout<<"Total="<<N;
	//system("pause");
	return 0;
}
