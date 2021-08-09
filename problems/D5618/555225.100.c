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
		if (' ' == c[i])
			++n;
		++i;
	}
	printf("%d", n);
	return 0;
}
