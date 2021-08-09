#include <stdio.h>
int main()
{
	int	min, max, factor;
	scanf("%d%d%d", &min, &max, &factor);
	for (; min <= max; ++min)
		if (min % factor == 0)
			printf("%d ", min);
	return 0;
}
