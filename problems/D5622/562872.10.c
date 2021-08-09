#include <stdio.h>
#include <string.h>
int main()
{
	int i=0;
	char str[21];
	char ch;
	memset(str,'\0',sizeof(str));
	scanf("%s",str);
	scanf("%c",&ch);
	while (str[i])
	{
		if (str[i]!=ch)
			printf("%c",str[i]);
		++i;
	}
	printf("\n");
	return 0;
}
