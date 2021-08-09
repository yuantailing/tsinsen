#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int width;
	cin >> width;
	int n = width >> 2;
	char sqr[50][50];
	for (int i = 0; i < width; i++)
		for (int j = 0; j < width; j++)
			sqr[i][j] = ' ';
	for (int i = 0; i <= n; i++)
		for (int j = i * 2; j < 4 * n + 2 - i * 2; j++) {
			sqr[i*2][j] = '*';
			sqr[j][i*2] = '*';
			sqr[4*n-i*2+1][j] = '*';
			sqr[j][4*n-i*2+1] = '*';
		}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++)
			cout << sqr[i][j];
		cout << endl;
	}
	//system("pause");
	return 0;
}
