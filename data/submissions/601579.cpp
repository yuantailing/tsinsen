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

bool first=true;

void Work(int n)
{
	if (n==2) cout<<"2";
	else if (n==1) cout<<"2(0)";
	else if (n==0) cout<<"0";
	else
	{
		bool second=true;
		for (int i=31;i>=2;i--)
		{
			if ((n>>i)%2)
			{
				if (first||second)
				{
					first=false;
					second=false;
					cout<<"2(";
					Work(i);
					cout<<")";
				}
				else
				{
					cout<<"+2(";
					Work(i);
					cout<<")";
				}
			}
		}
		{
			int i=1;
			if ((n>>i)%2)
			{
				if (first||second)
				{
					first=false;
					second=false;
					cout<<"2";
				}
				else
				{
					cout<<"+2";
				}
			}
		}
		{
			int i=0;
			if ((n>>i)%2)
			{
				if (first||second)
				{
					first=false;
					second=false;
					cout<<"2(";
					Work(i);
					cout<<")";
				}
				else
				{
					cout<<"+2(";
					Work(i);
					cout<<")";
				}
			}
		}
	}
}

int main(){
	int N;
	cin>>N;
	Work(N);
	//system("pause");
	return 0;
}
