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
	bool ok=false;
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
					ok=true;
					strcpy(&str[j],&str[j+1]);
					cout<<str;
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
					ok=true;
					for (int k=0;k<i;k++)
						printf("%c",str[k]);
					printf("%c",a2);
					printf("%s",&str[i]);
					break;
				}
		}
		break;
	case 'R':
		{
			scanf(" %c %c",&a1,&a2);
			for (int j=0;str[j];j++)
				if (str[j]==a1)
				{
					str[j]=a2;
					ok=true;
				}
			if (ok)
				cout<<str;
		}
		break;
	}
	if (!ok)
		cout<<"wrong";
	//system("pause");
	return 0;
}
