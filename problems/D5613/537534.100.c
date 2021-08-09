#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	return 0;
}
int main()
{
	int a[21];
	int i = 0;
	do
	{
		scanf("%d", &a[i++]);
	}
	while (a[i - 1]);
	qsort(a, i - 1, sizeof(int), cmp);
	printf("%d", a[i-3]);
	//system("pause");
	return 0;
}
