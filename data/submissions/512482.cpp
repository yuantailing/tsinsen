#include <iostream>
using namespace std;
int way(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 0) return 1;
	return way(n - 1) + way(n - 2) + way(n - 3);
}
int main()
{
	int n;
	cin >> n;
	cout << way(n);
	return 0;
}
