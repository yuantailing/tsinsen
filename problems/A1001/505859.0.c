#include<stdio.h>
int main(){
	int a,i;
	for (a=0;a<64;++a){
		for (i=5;i>=0;--i){
			printf("%d",(a>>i) % 2);
		}
		printf("\n");
	}
}
