#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int i;
	int m, n, l;
	for (i = 100; i < 1000; ++i)
	{
		m = i / 100;
		n = (i / 10 ) % 10;
		l = i % 10;
		if (i == m * m * m + n * n * n + l * l * l)
			cout << i << endl;
	}
	return 0;
}
