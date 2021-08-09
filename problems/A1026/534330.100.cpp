#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int cmp(const void *a,const void *b){
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a > *(int*)b) return -1;
	return 0;
}

int main(){
	int i, j, k;
	char t[101];
	int a[27];
	cin >> t;
	memset(a, 0, sizeof(a));
	for (i = 0;i < strlen(t); ++i) ++a[t[i] - 'a'];
	for (i = 0;i < 27; ++i)
		if (a[i] > 0) printf("%c %d\n",i + 'a',a[i]);
	//system("pause");
	return 0;
}
