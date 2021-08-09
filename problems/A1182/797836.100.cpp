#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	int *v = new int[N];
	int top = 0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		int j = top - M >= 0 ? top - M : 0;
		for (; j < top; j++)
			if (v[j] == x) break;
		if (j == top)
			v[top++] = x;
	}
	cout << top;
	return 0;
}
