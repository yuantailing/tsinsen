#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
using namespace std;

int comp(const void*a, const void*b)
{
	if (*(int*)a>*(int*)b) return 1;
	else if (*(int*)a==*(int*)b) return 0;
	else return -1;
}

int main()
{
	int N;
	cin>>N;
	int a[1010];
	for (int i=0;i<N;i++)
		cin>>a[i];
	int b[1010];
	for (int i=0;i<N-1;i++)
		b[i]=abs(a[i+1]-a[i]);
	qsort(b,N-1,sizeof(int),comp);
	bool happy=true;
	for (int i=0;i<N-1;i++)
		if (b[i]!=i+1) happy=false;
	if (happy)
		cout<<"I'm happy!!";
	else
		cout<<"I'm unhappy!!";
	//system("pause");
	return 0;
}
