#include <stdio.h>
#include <string.h>
int main()
{char a[20],c,s;
int i,j,d;
gets(a);
j=strlen(a);
for (i=0;i<j;i++)
{c=a[i];
d=c-'A';
	if((d>=0)&&(d<=26))  a[i]=c+32;
	if ((d>=32)&&(d<=58))a[i]=c-32;
}
puts(a);
return(0);
}
