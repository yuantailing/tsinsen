#include <iostream>
using namespace std;

int main(void)
{
	int a,x,b,y,m;
	char junk;
	cin >> a;
	cin >> junk;
	cin >> b;
	cin >> junk;
	cin >> m;
	for (x=1;x<=1000;++x)
		for (y=x;y<=1000;++y)
			if (a * x + b * y <= m)
				cout << x << ',' << y << endl;
	return 0;
}
