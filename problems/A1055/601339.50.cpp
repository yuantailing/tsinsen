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

int cmp(const void*a, const void*b)
{
	if (*(string*)a>*(string*)b) return 1;
	else if (*(string*)a==*(string*)b) return 0;
	else return -1;
}

int main()
{
	int n;
	cin>>n;
	string*group=new string [n];
	for (int i=0;i<n;i++)
		cin>>group[i];
	qsort(group,n,sizeof(string),cmp);
	string str;
	cin>>str;
	int i;
	for (i=0;i<n;i++)
		if (group[i]==str) break;
	if (i==n) cout<<"The End";
	else cout<<group[i+1];
	delete [] group;
	system("pause");
	return 0;
}
