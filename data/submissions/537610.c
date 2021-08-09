#include <stdio.h>
int main()
{
	enum person {jia, yi, bing, ding};
	enum person i;
	int p1, p2, p3, p4;
	for (i = jia; i <= ding; ++i)
	{
		p1 = i != yi && i == ding;
		p2 = i != yi && i == bing;
		p3 = i != jia && i == yi;
		p4 = i != ding;
		if (p1 && p2 && p3 && p4) break;
		if (!(p1 || p2 || p3)) break;
	}
	switch (i)
	{
	case jia: printf("A"); return 0;
	case yi: printf("B"); return 0;
	case bing: printf("C"); return 0;
	case ding: printf("D"); return 0;
	};
	printf("No answer");
	return 0;
}
