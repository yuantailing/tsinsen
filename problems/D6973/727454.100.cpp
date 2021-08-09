#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
return a % b ? gcd(b, a % b) : b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}
