#include <stdio.h>
int main()
{
	int i, j;
	int m, n;
	scanf("%d%d", &m, &n);
	if (m == 0 || n == 0)
		return 0;
	printf("+");
	for (i = 0; i < n; ++i)
		printf("-+");
	printf("\n");
	for (i = 0; i < m; ++i){
		printf("|");
		for (j = 0; j < n; ++j)
			printf(" |");
		printf("\n");
		printf("+");
		for (j = 0; j < n; ++j)
			printf("-+");
		printf("\n");
	}
	return 0;
}
