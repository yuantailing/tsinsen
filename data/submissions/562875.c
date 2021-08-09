#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	char b[100];
	int ac[30];
	int bc[30];
	int aa, bb;
	int i;
	int flag = 1;
	scanf("%s", a);
	scanf("%s", b);
	aa = strlen(a);
	bb = strlen(b);
	memset(ac, 0, sizeof(ac));
	memset(bc, 0, sizeof(bc));
	for (i = 0; i < aa; ++i)
	{
		if (a[i] <= 'Z')
			++ac[a[i] - 'A'];
		else
			++ac[a[i] - 'a'];
	}
	for (i = 0; i < bb; ++i)
	{
		if (b[i] <= 'Z')
			++bc[b[i] - 'A'];
		else
			++bc[b[i] - 'a'];
	}
	for (i = 0; i < 26; ++i)
		if (ac[i] != bc[i])
			flag = 0;
	if (flag)
		printf("Y");
	else
		printf("N");
	return 0;
}
