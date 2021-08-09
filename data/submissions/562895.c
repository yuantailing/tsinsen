#include <stdio.h>
#include <string.h>
int main()
{
	char t[30];
	char c = 0;
	char d[30];
	int len;
	int i;
	int j=0;
	if (!scanf("%s", t))
		return 0;
	len = strlen(t);
	if (!len)
		return 0;
	if (!scanf("%c", &c))
		return 0;
	if (!scanf("%c", &c))
		return 0;
	if (!c)
		return 0;
	len = strlen(t);
	for (i = 0; i <= len; ++i)
	{
		if (t[i] != c)
			d[j++] = t[i];
	}
	puts(d);
	return 0;
}
