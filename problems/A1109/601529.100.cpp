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

int a,b,c,d,e,f,g,h,i;
int aa,bb,cc,dd,ee,ff,gg,hh,ii;
int P;
bool used[10];
int ans;

void Work()
{
	if (a+b+d+f==P&&f+g+h+i==P&&i+e+c+a==P)
	{
		ans++;
		if (ans==1)
		{
			aa=a;
			bb=b;
			cc=c;
			dd=d;
			ee=e;
			ff=f;
			gg=g;
			hh=h;
			ii=i;
		}
	}
}

int main()
{
	memset(used,0,sizeof(used));
	cin>>P;
	for ( a=1;a<8;a++)
	{
		used[a]=1;
		for ( f=a+1;f<9;f++)
		{
			used[f]=1;
			for ( i=f+1;i<=9;i++)
			{
				used[i]=1;
				for ( b=1;b<=9;b++)
				if (!used[b])
				{
					used[b]=1;
					for ( d=b+1;d<=9;d++)
					if (!used[d])
					{
						used[d]=1;
						for ( g=1;g<=9;g++)
						if (!used[g])
						{
							used[g]=1;
							for ( h=g+1;h<=9;h++)
							if (!used[h])
							{
								used[h]=1;
								for ( c=1;c<=9;c++)
								if (!used[c])
								{
									used[c]=1;
									for ( e=c+1;e<=9;e++)
									if (!used[e])
									{
										used[e]=1;
										Work();
										used[e]=0;
									}
									used[c]=0;
								}
								used[h]=0;
							}
							used[g]=0;
						}
						used[d]=0;
					}
					used[b]=0;
				}
				used[i]=0;
			}
			used[f]=0;
		}
		used[a]=0;
	}
	if (!ans)
		cout<<"NO";
	else
		printf("%d\n%d\n%d %d\n%d %d\n%d %d %d %d",ans,aa,bb,cc,dd,ee,ff,gg,hh,ii);
	//system("pause");
	return 0;
}
