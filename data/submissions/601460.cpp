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

int contain[9]={0,120,40,85,50,100,140,70,100};
int a,b,c,d;

int main()
{
	bool ok=false;
	cin>>a>>b>>c>>d;
	for (int i=1;i<=8;i++)
		if (contain[i]>=a)
			for (int j=1;j<=8;j++)
				if (j!=i&&contain[j]>=b)
					for (int k=1;k<=8;k++)
						if (k!=i&&k!=j&&contain[k]>=c)
							for (int l=1;l<=8;l++)
								if (l!=i&&l!=j&&l!=k&&contain[l]>=d)
								{
									ok=true;
									printf("%d %d %d %d\n",i,j,k,l);
								}
	if (!ok)
		printf("-1");
	//system("pause");
	return 0;
}
