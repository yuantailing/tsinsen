#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

int isNumber(char c)
{
	if (c>='0'&&c<='0') return 1;
	return 0;
}

int main()
{
	char s[200];
	cin>>s;
	int pos=1;
	int sym;
	int i=0;
	int sum=atoi(s);
	int x;
	while (s[pos]!='=')
	{
		while (isNumber(s[pos]))
			pos++;
		sym=s[pos];
		if (sym=='=') continue;
		pos++;
		x=atoi(s+pos);
		if (sym=='+') sum+=x;
		if (sym=='-') sum-=x;
	}
	cout<<sum;
	//system("pause");
	return 0;
}
