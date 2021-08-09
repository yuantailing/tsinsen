#include <stdio.h>
int main()
{
	int i, j;
	scanf("%d", &i);
	for (; i > 0; --i)
	{
		for (j = i; j > 0; --j)
			printf("* ");
		printf("\n");
	}
	return 0;
}
