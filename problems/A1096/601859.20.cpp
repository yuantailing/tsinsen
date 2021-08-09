#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
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
	int n=-1;
	do
	{
		n++;
		scanf("%c",&s[n]);
	}while (s[n]!='\r'&&s[n]!='\n');
	s[n]=0;
	cin>>k;
	for (int i=0;i<=n-k;i++)
	{
		memcpy(a[i],s+i,k);
		a[i][k]='\0';
	}
	qsort(a,n-k,sizeof(char[8]),cmp);
	for (int i=0;i<=n-k;i++)
		//if (i==0||strcmp(a[i-1],a[i]))
			cout<<a[i]<<' ';
	//system("pause");
	return 0;
}
