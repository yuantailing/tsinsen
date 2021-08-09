#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

bool prime(int x)
{
	if (x<2) return false;
	if (x==2) return true;
	if (x%2==0) return false;
	int s=sqrt(x+1);
	for (int i=3;i<=s;i+=2)
		if (x%i==0) return false;
	return true;
}

int main()
{
	int a,b;
	int flag=0;
	cin>>a>>b;
	for (int i=a;i+2<=b;i++)
		if (prime(i)&&prime(i+2))
		{
			flag=1;
			cout<<i<<' '<<i+2<<endl;
		}
	if (!flag) cout<<-1;
	//system("pause");
	return 0;
}
