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
	printf("%c%c%c %d %o",a,b,c,n,n);
	system("pause");
	return 0;
}
