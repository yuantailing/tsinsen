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
	int is=0,not=0;
	string s;
	cin>>s;
	for (int i=s.length()-1;i>=0;i--)
	{
		char c=s[i];
		if (c=='G'||c=='C')
			++is;
		else
			++not;
	}
	printf("%d",(int)((double)is*100/(is+not)+0.5));
	//system("pause");
	return 0;
}
