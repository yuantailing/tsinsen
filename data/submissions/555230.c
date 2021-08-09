#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char c[100];
	int n = 1;
	int i = 0;
	gets(c);
	while (c[i] != 0)
	{
		if ('Z' < c[i])
			c[i] = c[i] - 'a' + 'A';
		else c[i] = c[i] - 'A' + 'a';
		++i;
	}
	printf("%s", c);
	return 0;
}
