#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int m=1;
	while (m*(m+1)/2<n) m++;
	int p=n-m*(m-1)/2;
	int q=m+1-p;
	cout<<q<<'/'<<p;
	//system("pause");
	return 0;
}
