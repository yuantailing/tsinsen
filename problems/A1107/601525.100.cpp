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

bool match[66][66];
bool today[66];

int main()
{
	int n;
	cin>>n;
	int team=1<<n;
	for (int day=1;day<=team-1;day++)
	{
		bool firstMatch=true;
		printf("<%d>",day);
		memset(today,0,sizeof(today));
		for (int j=1;j<=team;j++)
			if (!today[j])
			{
				for (int k=j+1;k<=team;k++)
					if ((!today[k])&&(!match[j][k]))
					{
						match[j][k]=match[j][k]=true;
						today[j]=today[k]=true;
						if (firstMatch)
						{
							firstMatch=false;
							printf("%d-%d",j,k);
						}
						else
							printf(",%d-%d",j,k);
						break;
					}
			}
		printf("\n");
	}
	//system("pause");
	return 0;
}
