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

#include <vector>
int n,m;
vector<int> go[100001];
vector<int> back[100001];
int value[100001];
int maxv[100001];
int minv[100001];

void TryGo(int n)
{
	if (maxv[n]==-1)
		maxv[n]=value[n];
	int size = go[n].size();
	for (int i=0;i<size;i++)
	{
		int city=go[n][i];
		if (maxv[city]==-1)
		{
			TryGo(city);
		}
		if (maxv[n]>maxv[city])
		{
			maxv[city]=maxv[n];
			TryGo(city);
		}
	}
}

void TryBack(int n)
{
	if (minv[n]==999)
		minv[n]=value[n];
	int size = back[n].size();
	for (int i=0;i<size;i++)
	{
		int city=back[n][i];
		if (minv[city]==-1)
		{
			TryGo(city);
		}
		if (minv[n]<minv[city])
		{
			minv[city]=minv[n];
			TryGo(city);
		}
	}
}

int Best()
{
	int best=0;
	for (int i=1;i<=n;i++)
	{
		if (maxv[i]!=-1 && minv[i]!=999)
			if (best<maxv[i]-minv[i])
				best=maxv[i]-minv[i];
	}
	return best;
}

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>value[i];
	}
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		go[a].push_back(b);
		back[b].push_back(a);
		if (c==2)
		{
			go[b].push_back(a);
			go[a].push_back(b);
		}
	}
	for (int i=1;i<=n;i++)
	{
		maxv[i]=-1;
		minv[i]=999;
	}
	TryGo(1);
	TryBack(n);
	//for (int i=1;i<=n;i++)
	//	cout<<maxv[i]<<'\t'<<minv[i]<<endl;
	cout<<Best();
	system("pause");
	return 0;
}
