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
	int n;
	int A[111][111];
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			cin>>A[i][j];
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			printf("%d ",A[i][j]+A[j][i]);
		printf("\n");
	}
	//system("pause");
	return 0;
}
