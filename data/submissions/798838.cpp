#include <iostream>
#include <string>
using namespace std;

string const &f(int n) {
	static string *v[100] = {new string(""), new string("()")};
	if (v[n]) return *v[n];
	v[n] = new string(string("(")+f(n-1)+f(n-2)+string(")"));
	return *v[n];
}

int main() {
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}
