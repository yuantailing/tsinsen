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
	int N,M;
	int a=0,b=0;
	cin>>N>>M;
	for (int i=0;i<=N;i++)
		for (int j=0;j<=N;j++)
		{
			for (int p=1;p<=N;p++)
				if (i+p<=N&&j+p<=M)
					a++;
			for (int p=1;p<=N;p++)
				for (int q=1;q<=M;q++)
					if (p!=q&&i+p<=N&&j+q<=M)
						b++;
		}
	cout<<a<<' '<<b;
	//system("pause");
	return 0;
}
