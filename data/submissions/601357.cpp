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
	int v1,v2,t,s,l;
	cin>>v1>>v2>>t>>s>>l;
	int T=0,R=0;
	int time=0;
	int stop=0;
	int stop_begin;
	while (T<l&&R<l)
	{
		time++;
		T+=v2;
		if (stop)
			if (time-stop_begin>s)
				stop=0;
		if (!stop)
		{
			R+=v1;
			if (R-T>=t)
			{
				stop=1;
				stop_begin=time;
			}
		}
	}
	if (T>R) cout<<'T'<<endl<<time;
	else if (T<R) cout<<'R'<<endl<<time;
	else cout<<'D'<<endl<<time;
	//system("pause");
	return 0;
}
