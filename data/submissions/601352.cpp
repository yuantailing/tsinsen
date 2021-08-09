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

int f(int x)
{
	int buf=0;
	while (x%2==0)
	{
		x/=2;
		++buf;
	}
	return buf;
}

int main()
{
	int n;
	cin>>n;
	for (int i=1;i<1<<n;i++)
		cout<<(char)('A'+f(i));
	//system("pause");
	return 0;
}
