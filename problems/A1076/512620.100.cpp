#include <iostream>

using namespace std;

/*
获取n的约数个数。
约定n>=1
*/
int getNumDivisor(int n)
{
	int i;
	int m=0;
	for (i = 1; i<=n; ++i)
		if (n % i == 0) ++m;
	return m;
}

int main()
{
	int n;
	cin >> n;
	cout << getNumDivisor(n) << endl;
	return 0;
}
