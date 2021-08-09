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

int a,b,c;
bool used[10];

void ResetUsed(){
	for (int i=0;i<10;i++)
		used[i]=false;
}

void SetUsed(int x){
	used[x/100]=true;
	used[(x/10)%10]=true;
	used[x%10]=true;
}

int main(){
	for (int a=123;a<322;a++)
	{
		b=a*2;
		c=a*3;
		ResetUsed();
		SetUsed(a);
		SetUsed(b);
		SetUsed(c);
		bool flag=true;
		for (int i=1;i<=9;i++)
			if (!used[i])
				flag=false;
		if (flag)
			printf("%d %d %d\n",a,b,c);
	}
	//system("pause");
	return 0;
}
