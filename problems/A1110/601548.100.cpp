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
	int a[30];
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
		for (int i=0;i<30;i++)
		{
			C.a[i]+=a[i]+B.a[i];
			while (C.a[i]>=10)
			{
				C.a[i]-=10;
				if (i<29) C.a[i+1]++;
			}
		}
		return C;
	}
	bool Judge(){if (a[0]<0) return false;else return true;}
	void Print()
	{
		if (a[0]<0)
		{
			cout<<a[0];
			return;
		}
		int dit=1;
		for (int i=0;i<30;i++)
		{
			if (a[i])
				dit=i+1;
		}
		for (int i=(dit-1)<20?dit-1:19;i>=0;i--)
			cout<<a[i];
	}
};


INT a[100][100];

int n,m;
int xx1,xx2,yy1,yy2;

INT A(int x, int y)
{
	if (a[x][y].Judge()) return a[x][y];
	else
	{
		INT t;
		t=0;
		if (x>1)
		if (y<yy1||y>yy2||x>xx2+1||x<xx1)
			t=t+A(x-1,y);
		if (y>1)
		if (x<xx1||x>xx2||y>yy2+1||y<yy1)
			t=t+A(x,y-1);
		a[x][y]=t;
		return t;
	}
}

int main()
{
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			a[i][j]=-1;
	a[1][1]=1;
	cin>>m>>n;
	cin>>xx1>>yy1>>xx2>>yy2;
	if (xx1>xx2) swap(xx1,xx2);
	if (yy1>yy2) swap(yy1,yy2);

	INT ANS=A(n,m);
	ANS.Print();

	//system("pause");
	return 0;
}
