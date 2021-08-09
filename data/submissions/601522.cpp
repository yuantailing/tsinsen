#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;

int N,M;
int v[2000];//v[i]:面值i至少要多少张邮票，无法达成视为0
int m=1;//第一个无法达成的面值是v[m]
int Max;
int MaxHave[20];
int MaxTop;
int have[20];
int top;

void Print()
{
	printf("m=%d\nhave=",m);
	for (int i=1;i<=top;i++)
		cout<<have[i]<<' ';
	cout<<endl;
}

void Try(const int n)
{
	for (int i=have[n-1]+1;i<=m;i++)//面值为i的邮票
	{
		have[++top]=i;
		int vsave[2000];
		int msave=m;
		memcpy(vsave,v,sizeof(v));
		for (int j=0;j<=N;j++)//贴j张
		{
			int ij=i*j;
			int t=(N-j)*have[top-1]+ij;
			for (int k=ij;k<=t;k++)//更新v[k]的值
				if (v[k]==0||v[k]>j+v[k-ij])
					if (v[k-ij]!=0||k-ij==0)
					{
						if (v[k-ij]<=N-j)
							v[k]=j+v[k-ij];
					}
					else if (k&i==0&&k/i<=N)
						v[k]=k/i;
		}
		while (v[m]) m++;
		if (n<M)
			Try(n+1);
		else if (m-1>=Max)//选字典序靠后的，虽然题目没说
		{
			Max=m-1;
			memcpy(MaxHave,have,sizeof(have));
			MaxTop=top;
		}

		have[top--]=0;
		memcpy(v,vsave,sizeof(v));
		m=msave;
	}
}

int main()
{
	cin>>N>>M;
	Try(1);
	for (int i=1;i<MaxTop;i++)
		cout<<MaxHave[i]<<' ';
	cout<<MaxHave[MaxTop]<<endl;
	cout<<"MAX="<<Max<<endl;
	//system("pause");
	return 0;
}
