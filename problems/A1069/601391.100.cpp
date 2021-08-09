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

int a[5][5];
int used[300];
int ans;
int k;
int sum;

void Print()
{
	for (int i=1;i<=4;i++)
	{
		for (int j=1;j<=4;j++)
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
}

bool Check()
{
	int t;
	t=0;
	for (int i=1;i<=4;i++)
	{
		t=0;
		for (int j=1;j<=4;j++)
		{
			t+=a[j][i];
		}
		if (t!=sum)
			return false;
	}
	{
		t=0;
		for (int i=1;i<=4;i++)
			t+=a[i][i];
		if (t!=sum)
			return false;
		t=0;
		for (int i=1;i<=4;i++)
			t+=a[i][5-i];
		if (t!=sum)
			return false;
	}
	for (int i=1;i<=4;i++)
	{
		t=0;
		for (int j=1;j<=4;j++)
		{
			t+=a[i][j];
		}
		if (t!=sum)
			return false;
	}
	return true;
}

void Fill(int x, int y)
{
	if (x==5)
	{
		//if (a[3][3]==10&&a[4][4]==9&&a[4][3]==6)
		//{
		//	Print();
		//}
		if (Check())
		{
			ans++;
		//	Print();
		}
		if (ans==k)
		{
			Print();
		//	system("pause");
			exit(0);
		}
		return;
	}
	if (x==4)
	{
		for (int i=1;i<=4;i++)
		{
			int t=sum-a[1][i]-a[2][i]-a[3][i];
			if (t>=1&&t<=16&&!used[t])
				a[4][i]=t;	
			else
				return;
		}
		if (a[4][1]!=a[4][2]&&a[4][1]!=a[4][3]&&a[4][1]!=a[4][4]&&a[4][2]!=a[4][3]&&a[4][2]!=a[4][4]&&a[4][3]!=a[4][4])
		{
			Fill(5,1);
		}
		for (int i=1;i<=4;i++)
			a[4][i]=0;
		return;
	}
	for (int i=1;i<=16;i++)
	{
		if (!used[i])
		{
			used[i]=1;
			a[x][y]=i;
			if (y==4)
			{
				int s=0;
				for (int h=1;h<=4;h++)
					s+=a[x][h];
				if (s==sum)
				{
					Fill(x+1,1);
				}
			}
			else
				Fill(x,y+1);
			used[i]=0;
			a[x][y]=0;
		}
	}
}

int main()
{
	cin>>k;
	sum=(1+4*4)*4*4/8;
	Fill(1,1);
	system("pause");
	return 0;
}
