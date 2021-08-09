#include <iostream>
using namespace std;

int solve(int k) {
	static int v[200];
	if (v[k]) return v[k];
	int sum = 0;
	for (int i = k / 2; i > 0; i--)
		sum += solve(i);
	return v[k] = sum + 1;
}

int main() {
	int k;
	cin >> k;
	cout << solve(k);
	return 0;
}
