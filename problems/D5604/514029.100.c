#include <stdio.h>
#include <stdlib.h>
int ToNumber(char *a)
{
	if (*a < 'A') return *a - '0';
	else return *a - 'A' + 10;
}
int main()
{
	char a, b, c;
	int n;
	int x,y,z;
	scanf("%c%c%c", &a, &b, &c);
	x = ToNumber(&a);
	y = ToNumber(&b);
	z = ToNumber(&c);
	n = x * 16 * 16 + y * 16 + z;
	if (x == 0 && y == 0) printf("%c %d %o", c, n, n);
	else if (x == 0) printf("%c%c %d %o", b, c, n, n);
	else printf("%c%c%c %d %o", a, b, c, n, n);
	return 0;
}
