#include <stdio.h>
int main()
{
	int n;
	int a;
	int x;
	scanf("%d", &n);
	if (n == 0)
	{
		printf("0");
		return 0;
	}
	while (n > 0)
	{
		x = 1;
		a = n;
		while (a > 9)
		{
			a /= 10;
			x *= 10;
		}
		n = n - a * x;
		printf("%d ", a);
	}
	return 0;
}
