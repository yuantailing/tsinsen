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

int s[20];
int top;
int n,m;

void Print()
{
	printf("%d=",n);
	for (int i=1;i<top;i++)
		printf("%d+",s[i]);
	printf("%d\n",s[top]);
}

void f1(int x)
{
	for (int i=1;i<x;i++)
	{
		s[++top]=i;
		f1(x-i);
		s[top--]=0;
	}
	s[++top]=x;
	Print();
	s[top--]=0;
}

void f2(int x)
{
	for (int i=1;i<x;i++)
	{
		s[++top]=i;
		if (s[top]>=s[top-1])
		f2(x-i);
		s[top--]=0;
	}
	s[++top]=x;
	if (s[top]>=s[top-1])
		Print();
	s[top--]=0;
}

int main()
{
	cin>>n>>m;
	if (m==1)
		f1(n);
	else
		f2(n);
	//system("pause");
	return 0;
}
