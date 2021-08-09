#include <stdio.h>
#include <stdlib.h>
int main()
{
	void *p = malloc(512000000);
	double  sale, rate;
	scanf("%lf%lf", &sale, &rate);
	printf("%.2lf", sale * rate);
	return (0);
}