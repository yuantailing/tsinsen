#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int cmp(const void*a,const void*b){
	if (*(int*)a>*(int*)b) return 1;
	else if (*(int*)a>*(int*)b) return -1;
	return 0;
}
int main(){
	char a[11],b[11];
	int flag1=1,flag2=1,flag3=1,flag4=1;
	cin >> a;
	cin >> b;
	if (strlen(a)==strlen(b)) flag1=0;
	for (int i=0;i<strlen(a);++i){
		if (a[i]!=b[i]) flag2=0;
		if (a[i]>'Z') a[i]=a[i]-'a'+'A';
		if (b[i]>'Z') b[i]=b[i]-'a'+'A';
		if (a[i]!=b[i]) flag3=0;
	}
	if (flag1) cout<<1;
	else if (flag2) cout<<2;
	else if (flag3) cout<<3;
	else cout<<4;
	//system("pause");
	return 0;
}
