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

int main(){
	int a,n,m,x;
	cin>>a>>n>>m>>x;
	int shang[30];
	int xia[30];
	shang[1]=a;
	xia[1]=0;
	int p;
	int t=0;
	while (1)
	{
		shang[2]=xia[2]=t;
		p=a;
		for (int i=3;i<=n;i++)
		{
			shang[i]=shang[i-1]+shang[i-2];
			xia[i]=shang[i-1];
			p=p+shang[i]-xia[i];
		}
		if (p==m)
		{
			int sum=0;
			for (int i=1;i<=x;i++)
				sum=sum+shang[i]-xia[i];
			cout<<sum;
			exit(0);
		}
		t++;
	}
	system("pause");
	return 0;
}
