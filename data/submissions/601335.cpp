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

int main()
{
	int N;
	char s[10][101];
	cin>>N;
	for (int i=0;i<N;i++)
		cin>>s[i];
	int len=strlen(s[0]);
	int a[101][128];
	memset(a,0,sizeof(a));
	for (int i=0;i<N;i++)
		for (int j=0;j<len;j++)
			a[j][s[i][j]]++;
	for (int j=0;j<len;j++)
	{
		char ch='A';
		for (char c='C';c<='T';c++)
			if (a[j][c]>a[j][ch])
				ch=c;
		cout<<ch;
	}
	//system("pause");
	return 0;
}
