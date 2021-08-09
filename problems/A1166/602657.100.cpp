#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>
#include <cstdarg>
using namespace std;

int times[128];
int maxn = 0;
int minn = 100;

bool isPrime(int x)
{
	if (x<2) return false;
	for (int i=2;i<x;i++)
		if (x%i==0)
			return false;
	return true;
}

int main()
{
	char s[101];
	cin>>s;
	int len = strlen(s);
	for (int i=0;i<len;i++)
		times[s[i]]++;
	for (int i='a';i<='z';i++)
	{
		if (times[i]>maxn)
			maxn=times[i];
		if (times[i]>0 && times[i]<minn)
			minn=times[i];
	}
	int delta=maxn-minn;
	if (isPrime(delta))
		cout<<"Lucky Word"<<endl<<delta;
	else
		cout<<"No Answer"<<endl<<0;
	//system("pause");
	return 0;
}
