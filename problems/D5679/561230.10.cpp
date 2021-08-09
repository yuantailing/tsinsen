#include <iostream>
using namespace std;
void sieve(bool isPrime[], int n) {
	for (int i = 2; i * 2 <= n; ++i)
		if (isPrime[i])
			for (int j = i + 1; j <= n; ++j)
				if (!(j % i))
					isPrime[j] = false;
}
void Disp(bool a[], int n)
{
	for (int i = 1; i < n; i++)
	if (a[i]) cout << i << " " ;
	cout << endl;
}
int main()
{
	int n = 0;
	cin >> n;
	if (n < 2)
		return 0;
	bool* isPrime = new bool[n];
	isPrime[0] = false;
	isPrime[1] = false;
	sieve(isPrime, n);
	Disp(isPrime, n);
	return 0;
}
