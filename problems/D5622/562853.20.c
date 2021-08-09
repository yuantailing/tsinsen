#include <stdio.h>
#include <string.h>
int main()
{
	int i=-1;
	char str[21];
	char ch;
	gets(str);
	fflush(stdin);
	scanf("%c",&ch);
	while (str[++i])
		if (str[i]!=ch)
			printf("%c",str[i]);
	printf("\n");
	return 0;
}
