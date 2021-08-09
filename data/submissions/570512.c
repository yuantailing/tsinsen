#include <stdio.h>
#include <string.h>

int scmp(char * a, char * b)
{
	while (*a != 0 || *b != 0)
	{
		if (*a > *b)
			return 1;
		if (*a < *b)
			return -1;
		++a;
		++b;
	}
	return 0;
}

int main()
{
	char a[30];
	char b[30];
	scanf("%s", a);
	scanf("%s", b);
	printf("%d", scmp(a, b));
	return 0;
}
