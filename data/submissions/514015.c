#include <stdio.h>
int main()
{
	int n;
	int a[10];
	int *b = a;
	scanf("%d", &n);
	if (n==0)
	{
		printf("0");
		return 0;
	}
	while (n > 0)
	{
		*b = n % 10;
		n /= 10;
		++b;
	}
	while (b>a)
		printf("%d ", *--b);
	return 0;
}
