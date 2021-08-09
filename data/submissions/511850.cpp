#include <iostream>
using namespace std;
int main(){
	int n;
	int A[110][110];
	int X[110];
	int i, j, k;
	int sum;
	cin >> n;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			cin >> A[i][j];
	for (i = 1; i <= n; ++i)
		cin >> X[i];
	for (i = 1; i <= n; ++i)
	{
		sum=0;
		for (j = 1; j <= n; ++j)
			sum += A[i][j] * X[j];
		cout << sum << endl;
	}
	return 0;
}
