#include <stdio.h>
#include <string.h>
int main()
{
	char t[30];
	char c;
	char d[30];
	int len;
	int i;
	int j=0;
	scanf("%s", t);
	len = strlen(t);
	if (!len)
		return 0;
	scanf("%c", &c);
	scanf("%c", &c);
	len = strlen(t);
	for (i = 0; i <= len; ++i)
	{
		if (t[i] != c)
			d[j++] = t[i];
	}
	puts(d);
	return 0;
}
