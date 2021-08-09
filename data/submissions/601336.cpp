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

void read_ge(int x)//x<10
{
	switch(x)
	{
	case 0: cout<<"ling "; break;
	case 1: cout<<"yi "; break;
	case 2: cout<<"er "; break;
	case 3: cout<<"san "; break;
	case 4: cout<<"si "; break;
	case 5: cout<<"wu "; break;
	case 6: cout<<"liu "; break;
	case 7: cout<<"qi "; break;
	case 8: cout<<"ba "; break;
	case 9: cout<<"jiu "; break;
	}
}

void read_wan(int x)//x<10000
{
	int weishu=x/1000?4:x/100?3:x/10?2:1;
	if (weishu==1) read_ge(x);
	if (weishu==2)
	{
		if (x/10>1) read_ge(x/10);
		cout<<"shi ";
		if (x%10) read_ge(x%10);
	}
	if (weishu==3)
	{
		read_ge((x/100)%10);
		cout<<"bai ";
		int shiwei=(x/10)%10;
		int gewei=x%10;
		if (shiwei)
		{
			read_ge(shiwei);
			cout<<"shi ";
			if (gewei)
				read_ge(gewei);
		}
		else
		{
			if (gewei)
			{
				cout<<"ling ";
				read_ge(gewei);
			}
		}
	}
	if (weishu==4)
	{
		read_ge(x/1000);
		cout<<"qian ";
		int baiwei=(x/100)%10;
		if (baiwei)
		{//Copy
			read_ge((x/100)%10);
			cout<<"bai ";
			int shiwei=(x/10)%10;
			int gewei=x%10;
			if (shiwei)
			{
				read_ge(shiwei);
				cout<<"shi ";
				if (gewei)
					read_ge(gewei);
			}
			else
			{
				if (gewei)
				{
					cout<<"ling ";
					read_ge(gewei);
				}
			}
		}
		else
		{
			int shiwei=(x/10)%10;
			int gewei=x%10;
			if (shiwei)
			{
				cout<<"ling ";
				read_ge(shiwei);
				cout<<"shi ";
				if (gewei)
					read_ge(gewei);
			}
			else
			{
				if (gewei)
				{
					cout<<"ling ";
					read_ge(gewei);
				}
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	if (n<10000)
		read_wan(n);
	else if (n<100000000)
	{
		read_wan((n/10000)%10);
		cout<<"wan ";
		if (n%10000)
		{
			if ((n/1000)%10==0)
				cout<<"ling ";
			if ((n%10000)/10==1)
				cout<<"yi ";
			read_wan((n%10000));
		}
	}
	else
	{
		read_wan(n/100000000);
		cout<<"yi ";
		if (n%100000000)
		{
			if ((n/10000)%10000==0)
			{
				cout<<"ling ";

				if ((n%10000)/10==1)
					cout<<"yi ";
				read_wan(n%10000);
			}
			else
			{
				if ((n/10000000)%10==0)
					cout<<"ling ";
				if ((n%100000000)/100000==1)
					cout<<"yi ";
				read_wan((n/10000)%10000);
				cout<<"wan ";
				if (n%10000)
				{
					if ((n/1000)%10==0)
						cout<<"ling ";
					if ((n%10000)/10==1)
					cout<<"yi ";
					read_wan(n%10000);
				}
			}
		}
	}
	//system("pause");
	return 0;
}
