#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	char c[100];
	unsigned int n = 0;
	int i = 0;
	int l = 0;
	scanf("%s", c);
	l = strlen(c);
	while (i < l)
	{
		n <<= 1;
		n += c[i] - '0';
		i++;
	}
	printf("%d", n);
	return 0;
}
