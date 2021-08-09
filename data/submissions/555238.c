#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int c[100];
	int n = 0;
	int i = 0;
	int t;
	do{
		scanf("%d", &c[n]);
		++n;
	} while (c[n - 1] != 0);
	--n;
	for (i = 0;i < n / 2; ++i){
		t = c[i];
		c[i] = c[n - 1 - i];
		c[n - 1 - i] = t;
	}
	for (i = 0; i < n; ++i)
		printf("%d ", c[i]);
	return 0;
}
