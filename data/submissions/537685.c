#include <stdio.h>
int main()
{
	enum person {jia, yi, bing, ding, noanswer};
	enum person i;
	int p1, p2, p3, p4;
	for (i = jia; i <= ding; ++i)
	{
		if ((i != yi) ^ (i == ding)) continue;
		if ((i != yi) ^ (i == bing)) continue;
		if ((i != jia) ^ (i == yi)) continue;
		break;
	}
	switch (i)
	{
	case jia: printf("A"); return 0;
	case yi: printf("B"); return 0;
	case bing: printf("C"); return 0;
	case ding: printf("D"); return 0;
	default: printf("No answer"); return 0;
	};
	return 0;
}
