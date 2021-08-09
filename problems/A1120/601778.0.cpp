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
	int n=0;
	int x;
	int last=-1;
	while (scanf("%d",&x)!=EOF)
	{
		if (x>last) n++;
		last=x;
	}
	cout<<n;
	//system("pause");
	return 0;
}
