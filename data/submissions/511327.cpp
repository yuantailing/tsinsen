#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	int a,b,c,d,e,f;
	for (a = 0; a <= 1; ++a)
	for (b = 0; b <= 1; ++b)
	for (c = 0; c <= 1; ++c)
	for (d = 0; d <= 1; ++d)
	for (e = 0; e <= 1; ++e)
	for (f = 0; f <= 1; ++f)
	if ((a+b+c+d+e+f) % 2 == 1)
		cout << a << b << c << d << e << f << endl;
	return 0;
}
