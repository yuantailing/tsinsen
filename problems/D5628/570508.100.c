#include <stdio.h>
#include <string.h>

int f(int x)
{
	int a = 0;
	while (x > 0)
	{
		a *= 10;
		a += x % 10;
		x /= 10;
	}
	return a;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", f(f(a) + f(b)));
	return 0;
}
