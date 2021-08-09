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

typedef struct _GRADE{
	int k;
	int s;
}GRADE;

int cmp(const void*a, const void*b)
{
	if (((GRADE*)a)->s>((GRADE*)b)->s) return -1;
	else if (((GRADE*)a)->s<((GRADE*)b)->s) return 1;
	else if (((GRADE*)a)->k<((GRADE*)b)->k) return -1;
	else return 1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	GRADE g[5555];
	for (int i=0;i<n;i++)
		cin>>g[i].k>>g[i].s;
	qsort(g,n,sizeof(GRADE),cmp);
	int line=g[(int)(m*1.5-1)].s;
	int sum=0;
	for (int i=0;i<n;i++)
		if (g[i].s>=line) ++sum;
	cout<<line<<' '<<sum<<endl;
	for (int i=0;i<sum;i++)
		cout<<g[i].k<<' '<<g[i].s<<endl;
	//system("pause");
	return 0;
}
