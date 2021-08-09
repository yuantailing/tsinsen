#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>
#include <cstdarg>
using namespace std;

int need[10]={6,2,5,5,4,5,6,3,7,6};

int Need(int n)
{
	int sum=0;
	if (n<10)
		return need[n];
	else
	while (n>0)
	{
		sum+=need[n%10];
		n/=10;
	}
	return sum;
}

int main()
{
	int A,B;
	int n;
	int ans=0;
	cin>>n;
	n-=4;
	for (A=0;A<1000;A++)
	{
		int needA=Need(A);
		if (needA>=n)
			continue;
		for (B=A;B<1000;B++)
		{
			int needB=Need(B);
			if (needA+needB>=n)
				continue;
			int C=A+B;
			int needC=Need(C);
			if (needA+needB+needC==n)
			{
				ans++;
				if (A!=B)
					ans++;
			}
		}
	}
	cout<<ans;
	//system("pause");
	return 0;
}
