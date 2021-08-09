#include <stdio.h>
int main()
{
	char t;
	while (t!=10 && t!=13)
	{
		scanf("%c",&t);
		printf("%c ",t);
	}
	return 0;
}
