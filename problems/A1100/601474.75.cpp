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
	int a,b;
	cin>>a>>b;
	printf("%4d\n",a);
	printf("*%3d\n",b);
	printf("----\n");
	if (b<10||b%10==0||a%10==0)
		printf("%4d\n",a*b);
	else
	{
		printf("%4d\n",a*(b%10));
		printf("%3d\n",a*(b/10));
		printf("----\n");
		printf("%4d\n",a*b);
	}

	//system("pause");
	return 0;
}
