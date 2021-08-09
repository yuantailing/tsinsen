#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <algorithm>
using namespace std;

char s[2000];
int n,k;
char a[2000][8];

int cmp(const void *a, const void *b)
{
	return strcmp((const char*)a,(const char*)b);
}

int main()
{
	cin>>s;
	int n=strlen(s);
	cin>>k;
	for (int i=0;i<=n-k;i++)
		memcpy(a[i],s+i,k);
	qsort(a,n-k+1,sizeof(char[8]),cmp);
	for (int i=0;i<=n-k;i++)
		//if (i==0||strcmp(a[i-1],a[i]))
			cout<<a[i]<<' ';
	//system("pause");
	return 0;
}
