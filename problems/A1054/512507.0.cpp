#include <iostream>
#include <cmath>
using namespace std;
int zs(int n)
{
	int i;
	if (n % 2 == 0) return 0;
	for (i = 3; i <= sqrt(n + 1); i+=2)
		if (n % i == 0) return 0;
	return 1;
}
int main()
{
	int n;
	cin >> n;
	if (n == 2)
	{
		cout << 3;
		exit(0);
	}
	while (n += 2)
	{
		if (zs(n) == 1)
		{
			cout << n;
			exit(0);
		}
	}
	return 0;
}
