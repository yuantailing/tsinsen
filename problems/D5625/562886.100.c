#include <stdio.h>
#include <string.h>
int main()
{
	char t[101];
	char w[101][101];
	int wn[101];
	int i = 0, j;
	int tailt = -1;
	int tailw = -1;
	int flag;
	memset(wn, 0, sizeof(wn));
	gets(t);
	while (t[i])
	{
		if (t[i] != ' ' && t[i] != '\0')
		{
			++i;
			continue;
		}
		if (t[i] == ' ')
		{
			flag = 0;
			++tailt;
			for (j = 0; j <= tailw; ++j)
			{
				if (i - tailt == strlen(w[j]))
				if (!strncmp(w[j], &t[tailt], strlen(w[j])))
				{
					++wn[j];
					tailt = i;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				++tailw;
				strncpy(&w[tailw][0], &t[tailt], i - tailt);
				w[tailw][i - tailt] = 0;
				wn[tailw] = 1;
				tailt = i;
			}
			++i;
		}
	}
{
			flag = 0;
			++tailt;
			for (j = 0; j <= tailw; ++j)
			{
				if (i - tailt == strlen(w[j]))
				if (!strncmp(w[j], &t[tailt], strlen(w[j])))
				{
					++wn[j];
					tailt = i;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				++tailw;
				strncpy(&w[tailw][0], &t[tailt], i - tailt);
				w[tailw][i - tailt] = 0;
				wn[tailw] = 1;
				tailt = i;
			}
			++i;
		}
	printf("%d", tailw + 1);
	return 0;
}
