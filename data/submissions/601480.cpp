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
	char str[100];
	char opt;
	char a,a1,a2;
	int i=0;
	do{
		scanf("%c",&str[i]);
		i++;
	}while (str[i-1]!='.');
	str[i]='\0';
	do
	{
		scanf("%c",&opt);
	}while (opt!='D'&&opt!='R'&&opt!='I');
	switch (opt)
	{
	case 'D':
		{
			scanf(" %c",&a);
			for (int j=0;str[j];j++)
				if (str[j]==a)
				{
					strcpy(&str[j],&str[j+1]);
					break;
				}
		}
		break;
	case 'I':
		{
			scanf(" %c %c",&a1,&a2);
			for (i--;i>=0;i--)
				if (str[i]==a1)
				{
					strcpy(&str[i+1],&str[i]);
					str[i]=a1;
					break;
				}
		}
		break;
	case 'R':
		{
			scanf(" %c %c",&a1,&a2);
			for (int j=0;str[j];j++)
				if (str[j]==a1)
					str[j]=a2;
		}
		break;
	}
	cout<<str;
	//system("pause");
	return 0;
}
