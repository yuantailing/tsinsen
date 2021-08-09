#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i=0;i<t;i++)
	{
		int N,M;
		cin>>N>>M;
		int a[10010];
		for (int i=0;i<N;i++)
			cin>>a[i];
		for (int i=0;i<M;i++)
		{
			int b,c;
			cin>>b>>c;
			int t=a[b-1];
			a[b-1]=a[c-1];
			a[c-1]=t;
		}
		for (int i=0;i<N;i++)
			cout<<a[i]<<endl;
	}
	//system("pause");
	return 0;
}
