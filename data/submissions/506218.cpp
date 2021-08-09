#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int camp(const void*a,const void*b){
	if (*(char*)a==0) return -1;
	if (*(char*)b==0) return 1;
	int i;
	for (i=0;i<2010;++i){
		if (((char*)a)[i]>((char*)b)[i]) return(1);
		if (((char*)a)[i]<((char*)b)[i]) return(-1);
	}
	return(0);
}

int main(){
	int i,j,l;
	char a[1010];
	cin>>a;
	l=0;
	while (a[++l]!=0);
	int k;
	cin>>k;
	char b[1010][1010];
	for (i=0;i<=l-k;++i){
		for (j=0;j<k;++j){
			b[i][j]=a[i+j];
		}
	}
	qsort(b,l-k,sizeof (char[1010]),camp);
	for (i=0;i<=l-k;++i) printf("%s ",b[i]);
}
