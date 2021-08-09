#include <iostream>
//#include <iomanip>
#include <string>
//#include <cstdlib>
//#include <cstdio>
//#include <cstring>
//#include <cmath>
//#include <cctype>
//#include <cassert>
using namespace std;

int main()
{
	int is=0,no=0;
	string s;
	cin>>s;
	for (int i=s.length()-1;i>=0;i--)
	{
		char c=s[i];
		if (c=='G'||c=='C')
			is++;
		else
			no++;
	}
	cout<<(int)((double)is*100/(is+no)+0.5);
	//system("pause");
	return 0;
}
