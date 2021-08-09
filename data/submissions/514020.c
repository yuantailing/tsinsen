#include <stdio.h>
inline void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int a;
	int b;
	int c;
	scanf("%d%d%d", &a, &b, &c);
	if (a < b) swap(&a, &b);
	if (a < c) swap(&a, &c);
	if (b < c) swap(&b, &c);
	printf("%d %d %d", a, b, c);
	return 0;
}
