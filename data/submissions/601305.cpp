#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int N;
char s[10000];
int times=0;

int f(int x)
{
	static int a[30];
	a[1]=a[2]=1;
	if (a[x]) return a[x];
	else
	{
		a[x]=f(x-1)+f(x-2);
		return a[x];
	}
}

int main()
{
	int n;
	cin >> n;
	while (n)
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += f(i);
		cout << sum;
		cin >> n;
	}
	//system("pause");
	return 0;
}
