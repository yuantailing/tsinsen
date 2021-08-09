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

int N,M;
int X1,Y1,X2,Y2;
int ans;

class POINT{
public:
	int x;
	int y;
};

POINT from[60][60];//到达(x,y)的前一步

int dx[4]={1,1,2,2};
int dy[4]={-2,2,-1,1};

void Jump1(int x, int y)
{
	POINT p;p.x=x;p.y=y;
	if (x==X2&&y==Y2)
	{
		ans++;
	}
	else if (x<X2)
	for (int i=0;i<4;i++)
		if (x+dx[i]<=N && y+dy[i]>=1 && y+dy[i]<=M && from[x+dx[i]][y+dy[i]].x==0)
		{
			from[x+dx[i]][y+dy[i]]=p;
			Jump1(x+dx[i],y+dy[i]);
		}
}

const long long e18=1000000000000000000;
long long jump[60][60];//到达(x,y)走法总数

long long Jump2(int x, int y)
{
	if (jump[x][y]!=-1)
		return jump[x][y];
	else if (x==X2&&y==Y2)
	{
		jump[x][y]=1;
		return 1;
	}
	else if (x<X2)
	{
		long long sum=0;
		for (int i=0;i<4;i++)
			if (x+dx[i]<=N && y+dy[i]>=1 && y+dy[i]<=M)
			{
				sum+=Jump2(x+dx[i],y+dy[i]);
			}
		jump[x][y]=sum%e18;
		return jump[x][y];
	}
	else
	{
		jump[x][y]=0;
		return 0;
	}
}

int main()
{
	cin>>N>>M>>X1>>Y1>>X2>>Y2;
	if (X1==0)
	{
		X2=N;
		Y2=M;
		Jump1(1,1);
		if (ans==0)
		{
			cout<<"NO";
			return 0;
		}
		POINT s[60];
		int top=0;
		POINT p;
		p.x=X2;
		p.y=Y2;
		while (p.y!=Y1)
		{
			s[++top]=p;
			p=from[p.x][p.y];
		}
		s[++top]=p;
		for (int i=top-1;i>1;i--)
			printf("(%d,%d)-",s[i].x,s[i].y);
		printf("(%d,%d)",s[1].x,s[1].y);
	}
	else
	{
		for (int i=0;i<60;i++)
			for (int j=0;j<60;j++)
				jump[i][j]=-1;
		cout<<Jump2(X1,Y1);
	}
	
	//system("pause");
	return 0;
}
