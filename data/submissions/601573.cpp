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

class INT{
public:
	int a[100];
	INT(){memset(a,0,sizeof(a));}
	INT& operator = (int b)
	{
		memset(a,0,sizeof(a));
		if (b<0)
		{
			a[0]=b;
			return *this;
		}
		int dit=0;
		while (b>0)
		{
			a[dit++]=b%10;
			b/=10;
		}
		return *this;
	}
	INT operator + (INT B)
	{
		INT C;
		for (int i=0;i<100;i++)
		{
			C.a[i]+=a[i]+B.a[i];
			while (C.a[i]>=10)
			{
				C.a[i]-=10;
				if (i<99) C.a[i+1]++;
			}
		}
		return C;
	}
	INT operator * (INT B)
	{
		INT C;
		for (int i=0;i<100;i++)
		{
			for (int j=0;i+j<100;j++)
			{
				C.a[i+j]+=a[i]*B.a[j];
				if (C.a[i+j]>=10)
				{
					if (i+j<99) C.a[i+j+1]+=C.a[i+j]/10;
					C.a[i+j]%=10;
				}
			}
		}
		return C;
	}
	void Print()
	{
		if (a[0]<0)
		{
			cout<<a[0];
			return;
		}
		int dit=1;
		for (int i=0;i<100;i++)
		{
			if (a[i])
				dit=i+1;
		}
		for (int i=(dit-1);i>=0;i--)
			cout<<a[i];
	}
};

int main(){
	INT S;
	S=0;
	INT X;
	X=1;
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		INT I;
		I=i;
		X=X*I;
		S=S+X;
	}
	S.Print();
	//system("pause");
	return 0;
}
