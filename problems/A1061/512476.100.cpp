#include <iostream>
using namespace std;
int main()
{
	int a,b;
	int i;
	cin >> a;
	b=0;
	for (i = 1; i <= a; ++i)
		if (a % i == 0) ++b;
	cout << b;
	return 0;
}
