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

void work(int x)
{
	cout<<x<<'=';
	int a=2;
	while (x>a)
	{
		if (x%a==0)
		{
			cout<<a<<'*';
			x/=a;
			a--;
		}
		a++;
	}
	cout<<a<<endl;
	return;
}

int main()
{
	int a,b;
	cin>>a>>b;
	for (int i=a;i<=b;i++)
		work(i);
	//system("pause");
	return 0;
}
