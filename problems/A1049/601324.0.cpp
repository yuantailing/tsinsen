#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>
using namespace std;

bool sug(bool p, bool q)
{
	if (q==false)
		if (p==true)
			return false;
	return true;
}

int main()
{
	bool chong=true, mao=true;
	int n,m;
	cin>>n>>m;
	char s[10][20];
	for (int i=0;i<m;i++)
		scanf("%s%s%s%s",&s[0],&s[3],&s[6],&s[8]);
	bool A[10];
	bool P[10];
	for (int t=0;t<1024;t++)
	{
		for (int j=0;j<10;j++)
			P[j]=(t<<j)%2;
		for (int i=0;i<m;i++)
		{
			bool zuo,you;
			if (s[i][3]=='X');
			if (s[i][3]=='A') zuo=A[s[i][4]-'0'];
			if (s[i][3]=='P') zuo=P[s[i][4]-'0'];
			if (s[i][8]=='A') you=A[s[i][9]-'0'];
			if (s[i][8]=='P') you=P[s[i][9]-'0'];
			if (s[i][6]=='~') A[i]=!you;
			if (s[i][6]=='>') A[i]=sug(zuo,you);
			if (s[i][6]=='^') A[i]=zuo&&you;
			if (s[i][6]=='v') A[i]=zuo||you;
		}
		if (A[m-1]==false) chong=false;
		else mao=false;
	}
	if (chong) cout<<1;
	else if (mao) cout<<-1;
	else cout<<0;
	//system("pause");
	return 0;
}
