#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int N;
char s[10000];
int times=0;

void swap(int pos)
{
	char t=s[pos];
	s[pos]=s[pos+1];
	s[pos+1]=t;
	times++;
}

int main()
{
	cin>>N;
	cin>>s;
	N=strlen(s);
	int mid=N/2;
	int single=0;

	for (int i=0;i<mid;i++)
	{
		if (s[i]!=s[N-1-i])
		{
			int j;
			for (j=N-2-i;s[i]!=s[j];j--);
			if (j==i)
			{
				if (single!=0)
				{
					cout<<"Impossible";
					return 0;
				}
				else
				{
					single=1;
					for (int k=i;k<mid;k++)
						swap(k);
					--i;
					continue;
				}
			}
			else
			{
				for (int k=j;k<N-1-i;k++)
					swap(k);
			}
		}
	}
	//cout<<s;
	cout<<times;
	//system("pause");
	return 0;
}
