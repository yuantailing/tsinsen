#include <iostream>
#include <algorithm>

using namespace std;

// 计算F(n)和F(n+1)除m的余数，分别放入fn和fn1中。
void calcF(int n, int m, int &fn, int &fn1)
{
	if (n==1)
	{
		fn=1;
		fn1=1;
		return;
	}
	if (n==2)
	{
		fn=1;
		fn1=2;
		return;
	}
	if (n%2==0)
	{
		int a=n/2;
		int b=n/2+1;
		int k1,k2;
		calcF(a,m,k1,k2);
		fn=(k2*k1+k1*(k2-k1+m))%m;
		fn1=(k2*k2+k1*k1)%m;
	}
	else
	{
		int a=n/2;
		int b=n/2+1;
		int c=n/2+2;
		int k1,k2,k3,k4;
		calcF(a,m,k1,k2);
		calcF(b,m,k4,k3);
		fn=(k2*k2+k1*k1)%m;
		fn1=(k3*k2+k2*(k3-k2+m))%m;
		if (k2!=k4)
		{
			cout<<"warning k2!=k4"<<endl;
		}
	}
}
