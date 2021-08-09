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

bool similar(char *aa, char *bb)
{
	char a[200],b[200];
	strcpy(a,aa);
	strcpy(b,bb);
	if (strcmp(a,b)==0)
		return true;
	int t=0;
	while (a[t]==b[t])
		t++;
	if (!a[t])
	{
		if (!b[t+1])
			return true;
		else
			return false;
	}
	if (!b[t])
	{
		if (!a[t+1])
			return true;
		else
			return false;
	}
	if (strlen(a)==strlen(b))
	{
		if (strcmp(a+t+1,b+t+1)==0)
			return true;
		else
			return false;
	}
	int lena=strlen(a);
	int lenb=strlen(b);
	if (lena>lenb)
	{
		if (strcmp(a+t+1,b+t)==0)
			return true;
		else
			return false;
	}
	else
	{
		if (strcmp(a+t,b+t+1)==0)
			return true;
		else
			return false;
	}
}

int main()
{
	char aim[30];
	int N;
	char vocabulary[200][30];
	cin>>aim;
	cin>>N;
	int i=0;
	for (int i=0;i<N;i++)
	{
		cin>>vocabulary[i];
		if (strcmp(aim,vocabulary[i])==0)
		{
			cout<<aim;
			return 0;
		}
	}
	for (int i=0;i<N;i++)
	{
		if (similar(aim,vocabulary[i]))
		{
			cout<<vocabulary[i];
			return 0;
		}
	}
	cout<<"NOANSWER";
	//system("pause");
	return 0;
}
