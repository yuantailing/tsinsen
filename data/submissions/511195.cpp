#include <iostream>
using namespace std;
int main(void)
{
	int i;
	int n;
	int c[1001];
	int a;
	cin >> n;
	for (i=1;i<=n;++i)
		cin >> c[i];
	cin >> a;
	i=0;
	while (++i<=n)
		if (a == c[i])
		{
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}
