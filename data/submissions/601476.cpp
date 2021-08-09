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
	int N,i,j;
	cin>>N>>i>>j;
	for (int k=1;k<=N;k++)
		printf("(%d,%d)",i,k);
	printf("\n");
	for (int k=1;k<=N;k++)
		printf("(%d,%d)",k,j);
	printf("\n");
	for (int k=1;k<=N;k++)
		if (k+j-i>=1&&k+j-i<=N)
			printf("(%d,%d)",k,k+j-i);
	printf("\n");
	for (int k=1;k<=N;k++)
		if (i+j-k>=1&&i+j-k<=N)
			printf("(%d,%d)",i+j-k,k);
	//system("pause");
	return 0;
}
