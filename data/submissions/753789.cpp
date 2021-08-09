#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
using namespace std;

int a[40][40];
int n;
int x,y;
int m;
int flag;
int d=1;

int next()
{
	if (d==1) return a[x+1][y];
	if (d==2) return a[x][y+1];
	if (d==3) return a[x-1][y];
	if (d==4) return a[x][y-1];
	else return -99;
}

void turn()
{
	if (d==4) d=1;
	else d++;
}

void gotonext()
{
	if (d==1) x++;
	if (d==2) y++;
	if (d==3) x--;
	if (d==4) y--;
}

void fill()
{
	a[x][y]=++m;
}

int main()
{

	memset(a,0,sizeof(a));
	cin>>n;
	assert(1<=n&&n<=30);
	int i,j;
	for (i=0;i<40;i++)
	{
		a[i][0]=a[0][i]=a[i][n+1]=a[n+1][i]=-1;
	}
	x=y=1;
	d=1;
	fill();
	flag=1;
	while (flag)
	{
		if (next()!=0)
		{
			turn();
			if (next()!=0)
				break;
		}
		else
		{
			gotonext();
			fill();
		}
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
			cout<<a[j][i]<<' ';
		cout<<endl;
	}
	//system("pause");
	return 0;
}
