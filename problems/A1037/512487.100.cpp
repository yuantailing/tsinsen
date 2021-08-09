#include <iostream>
using namespace std;
int way(int n)
{
	if (n == 4) return 7;
	if (n == 2) return 2;
	if (n == 3) return 4;
	return way(n - 1) + way(n - 2) + way(n - 3);
}
int main()
{
	int n;
	cin >> n;
	if (n >= 4 && n <=20)
		cout << way(n);
	else
		cout << 0;
	return 0;
}
