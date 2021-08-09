#include <stdio.h>
#include <string.h>
int main()
{
	int n;
	int b = 0;
	int max = 0;
	int mn = 0;
	int i;
	int t;
	int tail = 0;
	scanf("%d", &n);
	if (!n) return 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		if (t == tail) ++b;
		else
		{
			;if (b > mn)
			{
				mn = b;
				max = tail;
				tail = t;
				b = 1;
			}
			else
			{
				tail = t;
				b = 1;
			}
		}
	}
	if (b > mn)
	{
		mn = b;
		max = tail;
	}
	printf("%d", max);
	return 0;
}
