#include<stdio.h>
int main(){
	for(int i=0;i<25;++i)
	{
		for(int j=i;j>0;--j)printf("%c",'A'+j);
		for(int k=0;k<18-i;++k)printf("%c",'A'+k);
		printf("\n");
	}
}
