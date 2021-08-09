#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int longest(char*s)
{
	int len=strlen(s);
	int max=0;
	for (int i=0;i<len;i++)
		for (int j=i+max+1;j<len;j+=2)
		{
			int l=(j-i+1)/2;
			bool flag=true;
			for (int k=0;k<l;k++)
				if (s[i+k]!=s[i+l+k])
				{
					flag=false;
					break;
				}
			if (flag)
				max=j-i+1;
		}
	return max;
}

int main()
{
	char s[200];
	cin>>s;
	cout<<longest(s);
	//system("pause");
	return 0;
}
