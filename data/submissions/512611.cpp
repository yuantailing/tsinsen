#include <iostream>
using namespace std;
int main()
{
	int n;
	int i;
	int a;
	int max = -20000, min = 20000, sum = 0;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> a;
		if (a > max) max = a;
		if (a < min) min = a;
		sum += a;
	}
	cout << max << endl << min << endl << sum;
	return 0;
}
