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
	int L,N,p,mmax=0,mmin=0;
	cin>>L>>N;
	for (int i=0;i<N;i++)
	{
		cin>>p;
		int tmax=p>L+1-p?p:L+1-p;
		int tmin=p<L+1-p?p:L+1-p;
		mmax=tmax>mmax?tmax:mmax;
		mmin=tmin>mmin?tmin:mmin;
	}
	cout<<mmin<<' '<<mmax;
	//system("pause");
	return 0;
}
