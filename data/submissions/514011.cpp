#include <stdio.h>
int main()
{
	int t;
	double b;
	double s;
	scanf("%d%lf",&t,&b);
	if (t<=40) s=(double)t*b;
		else if (t<=50) s=40*b+(double)(t-40)*1.5*b;
			else s=40*b+15*b+(double)(t-50)*2*b;
	printf("%.2lf",s);
	return 0;
}
