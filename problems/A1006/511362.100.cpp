#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int i;
	for (i = 10; i < 100; ++i)
		cout << i << i % 10 << i / 10 << endl;
	return 0;
}
