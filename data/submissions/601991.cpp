#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
#include <fstream>
#include <algorithm>
using namespace std;

int n;

void w(int x)
{
	int a=(x/1)%10;
	int b=(x/10)%10;
	int c=(x/100)%10;
	int d=(x/1000)%10;
	if (a==2) n++;
	if (b==2) n++;
	if (c==2) n++;
	if (d==2) n++;
}

int main()
{
	int L,R;
	cin>>L>>R;
	for (int i=L;i<=R;i++)
		w(i);
	cout<<n;
	//system("pause");
	return 0;
}
