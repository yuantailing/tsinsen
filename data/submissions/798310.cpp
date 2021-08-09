#include <iostream>
#include <string>
using namespace std;

string f(int n) {
	if (n == 0) return string("");
	if (n == 1) return string("()");
	return string("(")+f(n-1)+f(n-2)+string(")");
}

int main() {
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}
