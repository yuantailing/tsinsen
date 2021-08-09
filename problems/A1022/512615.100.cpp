#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	cout << t / 3600 << ':' << (t / 60) % 60 << ':' << t % 60;
	return 0;
}
