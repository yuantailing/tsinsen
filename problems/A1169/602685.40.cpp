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

int s1[1001];
int s1top=-1;
int s2[1001];
int s2top=-1;
int a[1001];
int b[1001];
int n;
int head=0;
int tail=-1;
int times;
char ops[100000];
int opstop=-1;

bool op(char c)
{
	switch (c)
	{
	case 'a':
		if (head<n)
		{
			s1[++s1top]=a[head++];
			return true;
		}
		else
			return false;
	case 'b':
		if (s1top>=0)
		{
			b[++tail]=s1[s1top--];
			return true;
		}
		else
			return false;
	case 'c':
		if (head<n)
		{
			s2[++s2top]=a[head++];
			return true;
		}
		else
			return false;
	case 'd':
		if (s2top>=0)
		{
			b[++tail]=s2[s2top--];
			return true;
		}
		else
			return false;
	default:
		return false;
	}
}

bool opAnti(char c)
{
	switch (c)
	{
	case 'a':
		head--;a[head]=s1[s1top];s1top--;break;
	case 'b':
		s1top++;s1[s1top]=b[tail];tail--;break;
	case 'c':
		head--;a[head]=s2[s2top];s2top--;break;
	case 'd':
		s2top++;s2[s2top]=b[tail];tail--;break;
	}
	return true;
}

void Try()
{
	for (char ch='a';ch<='d';ch++)
		if (op(ch))
		{
			times++;
			if (times>1000000)
			{
				cout<<0;
				exit(0);
			}
			ops[++opstop]=ch;
			if (ch=='b'||ch=='d')
				if (b[tail]==tail+1)
				{
					if (tail==n-1)
					{
						for (int i=0;i<=opstop;i++)
							cout<<ops[i]<<' ';
						//system("pause");
						exit(0);
					}
				}
				else
				{
					opstop--;
					opAnti(ch);
					continue;
				}
			Try();
			opstop--;
			opAnti(ch);
		}
}

int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	Try();
	cout<<0;
	//system("pause");
	return 0;
}
