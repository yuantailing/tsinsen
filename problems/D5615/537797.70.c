#include <stdio.h>
int main()
{
	int i, j;
	int m, n;
	scanf("%d", &n);
	m = 1;
	for (i = 1; i <= n; ++i)
	{
		m *= i;
		while (!(m % 10))
			m /= 10;
		m = m % 10;
	}
	printf("%d", m);
	return 0;
}
