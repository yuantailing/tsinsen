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

void A(int n)
{
	int s=-1;
	printf("sin(1");
	for (int i=2;i<=n;i++)
	{
		printf("%csin(%d",s>0?'+':'-',i);
		s=-s;
	}
	for (int i=1;i<=n;i++)
		putchar(')');
}

void S(int n)
{
	for (int i=1;i<n;i++)
		putchar('(');
	for (int i=1;i<n;i++)
	{
		A(i);
		printf("+%d)",n+1-i);
	}
	A(n);
	printf("+1\n");
}


int main()
{
	int N;
	cin>>N;
	S(N);
	assert(N<201);
	//system("pause");
	return 0;
}
