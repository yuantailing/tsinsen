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

char s[60][60]=
{
	"zero ",
	"one ",
	"two ",
	"three ",
	"four ",
	"five ",
	"six ",
	"seven ",
	"eight ",
	"nine ",
	"ten ",
	"eleven ",
	"twelve ",
	"thirteen ",
	"fourteen ",
	"fifteen ",
	"sixteen ",
	"seventeen ",
	"eighteen ",
	"nineteen ",
	"twenty "
};

int main()
{
	strcpy(s[30],"thirty ");
	strcpy(s[40],"forty ");
	strcpy(s[50],"fifty ");
	for (int i=1;i<=9;i++)
		for (int base=30;base<=50;base+=10)
		{
			strcpy(s[base+i],s[base]);
			strcat(s[base+i],s[i]);
		}
	int h,m;
	cin>>h>>m;
	if (!m)
		cout<<s[h]<<"o'clock";
	else
		cout<<s[h]<<s[m];
	//system("pause");
	return 0;
}
