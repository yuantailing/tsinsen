#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <conio.h>

int alf(unsigned long int n){
	if (n < 10) return n;
	else{
		int i = 1;
		while (n > 1){
			if (n % 10 != 0)
				i *= n % 10;
			n /= 10;
		}
		return alf(i);
	}
}

int main(int argc, char *argv[])
{
	volatile unsigned long int n;
	scanf("%d", &n);
	printf("%d", alf(n));
	system("pause");
	return 0;
}
