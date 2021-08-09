#include <stdio.h>
#include <math.h>
int main(){
	char a,b,c,d;
	for (a='A';a<='D';a++)
		for (b='A';b<='D';b++)
			for (c='A';c<='D';c++)
				for (d='A';d<='D';d++)
					printf("%c%c%c%c\n",a,b,c,d);
	return(0);
}
