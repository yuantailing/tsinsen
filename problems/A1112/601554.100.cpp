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
	bool e1=false,e2=false,e3=false;
	char c;
	int last=1;//1表示符号
	int k=0;
	scanf("%c",&c);
	while (c!=';')
	{
		switch (c)
		{
		case'a':case'b':case'c':if (last==1) last=0;else e3=true; break;
		case'+':case'-':case'*':case'/':if (last==0) last=1;else e3=true; break;
		case'(':if (last!=1) e3=true;k++; break;
		case')':if (last!=0) e3=true;k--;if (k<0) e2=true; break;
		default:e1=true; break;
		}
		scanf("%c",&c);
	}
	if (k!=0) e2=true;

	if (e1) cout<<"ERROR 1";
	else if (e2) cout<<"ERROR 2";
	else if (e3) cout<<"ERROR 3";
	else cout<<"OK";
	//system("pause");
	return 0;
}
