#include <iostream>
using namespace std;
int main(){
	char   c[4];
	int	a[4];
	int	t;
	cin >> c[0];
	cin >> c[1];
	cin >> c[2];
	cin >> c[3];
	a[0] = (c[3] - '0' + 5) % 10;
	a[1] = (c[2] - '0' + 5) % 10;
	a[2] = (c[1] - '0' + 5) % 10;
	a[3] = (c[0] - '0' + 5) % 10;
	cout << a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	return 0;
}
