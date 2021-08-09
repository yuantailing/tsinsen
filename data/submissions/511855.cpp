#include <iostream>
using namespace std;
void maxmin_0(int a, int b, int c, int* max, int* min)
{
	*max = a;
	*min = a;
	if (b > a) *max = b;
		else *min = b;
	if (c > *max) *max = c;
	if (c < *min) *min = c;
}
void maxmin_1(int a, int b, int c, int& max, int& min)
{
	max = a;
	min = a;
	if (b > a) max = b;
		else min = b;
	if (c > max) max = c;
	if (c < min) min = c;
}

int main()
{
	int a, b, c, se, min, max;
	cin >> a >> b >> c >> se;
	if (se == 0)
		maxmin_0(a, b, c, &max, &min);
	else
		maxmin_1(a, b, c, max, min);
	cout << max << ' ' << min << endl;
}
