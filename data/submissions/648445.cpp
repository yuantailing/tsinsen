#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int width;
	cin >> width;
	int n = width >> 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n*2-i*2; j++)
			cout << ' ';
		for (int j = 0; j < i*2+1; j++)
			cout << " *";
		for (int j = 0; j < n*4-2-i*4; j++)
			cout << ' ';
		for (int j = 0; j < i*2+1; j++)
			cout << " *";
		cout << endl;
	}
	for (int i = 0; i < n*4+1; i++)
		cout << " *";
	cout << endl;
	for (int i = 0; i < n*2; i++) {
		for (int j = 0; j < 2+i*2; j++)
			cout << ' ';
		for (int j = 0; j < n*4-1-i*2; j++)
			cout << " *";
		cout << endl;
	}
	//system("pause");
	return 0;
}
