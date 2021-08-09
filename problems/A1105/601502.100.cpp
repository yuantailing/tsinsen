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

int n;
int w[30];
int p[30][30];
bool used[30];
int total;
int maxn;
struct _ROTE{
	int v[30];
	int top;
}rote,rote_max;

void Print()
{
	int sum=0;
	for (int i=1;i<rote_max.top;i++)
	{
		cout<<rote_max.v[i]<<'-';
		sum+=w[rote_max.v[i]];
	}
		cout<<rote_max.v[rote_max.top]<<endl;
		sum+=w[rote_max.v[rote_max.top]];
	cout<<"MAX="<<sum<<endl;
}

void Try(int x)
{
	if (!used[x])
	{
		total+=w[x];
		used[x]=1;
		rote.v[++rote.top]=x;
		bool last=true;
		for (int i=1;i<=n;i++)
			if (p[x][i]&&!used[i])
			{
				last=false;
				Try(i);
			}
		if (last)
		{
			if (total>maxn)
			{
				maxn=total;
				rote_max=rote;
			}
		}
		total-=w[x];
		used[x]=0;
		rote.v[rote.top--]=0;
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>w[i];//地雷数
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			cin>>p[i][j];//连通
			p[j][i]=p[i][j];
		}
	for (int i=1;i<=n;i++)
		Try(i);
	Print();
	//system("pause");
	return 0;
}





/*
int n;
int w[30];
int p[30][30];
int m[30][30];//m[i][j]:前i个地窖以j为终点，最多多少颗雷

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>w[i];//地雷数
	for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			cin>>p[i][j];//连通
			p[j][i]=p[i][j];
		}
	for (int i=1;i<=n;i++)//前i个地窖
	{
		for (int j=1;j<=i;j++)//以j为终点
		{
			m[i][j]=w[j];
			for (int k=1;k<=i-1;k++)
				if (p[k][j])
				{
					int newRecord=m[i-1][k]+w[j];
					if (newRecord>m[i][j])
						m[i][j]=newRecord;
				}
		}
	}
	for (int i=1;i<=n;i++)
		printf("%d ",m[n][i]);
	system("pause");
	return 0;
}
*/