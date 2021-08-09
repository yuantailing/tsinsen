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

char s[30][30];

int cmp(const void *aa, const void *bb)
{
	const char *a=(const char*)aa;
	const char *b=(const char*)bb;
	while (*a&&*b)
	{
		if (*a>*b) return 1;
		else if (*a<*b) return -1;
		a++;
		b++;
	}
	if (*a==0&&*b==0) return 0;
	if (*a) return cmp(a,bb);
	else return cmp(aa,b);
	return strcmp((const char*)a,(const char*)b);
}

int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>s[i];
	qsort(s,n,sizeof(char[30]),cmp);
	for (int i=n-1;i>=0;i--)
		cout<<s[i];
	//system("pause");
	return 0;
}
