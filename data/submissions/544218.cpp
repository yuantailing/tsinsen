#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <assert.h>
using namespace std;

#undef NAN
enum Flag { NORMAL, NAN, INF };
int gcd(int a, int b){
	if (a%b==0) return b;
	else return gcd(b,a%b);
}
class Fraction{
public:
	int a,b;
	Flag flag;
	void assign(int num,int den){
		a=num;b=den;setflag();}
	double convert(Flag&fflag){
		fflag=flag;
		if (a==0) return 0;
			else return (double)a/b;}
	void invert(){a^=b;b=a^b;a^=b;setflag();}
	void print();
	void setflag(){
		if (b!=0) flag=NORMAL;
		else if (a==0&&b==0) flag=NAN;
		else if (b==0) flag=INF;}
};
void Fraction::print(){
	int t;
	int aa=a,bb=b;
	if (bb!=0) t=gcd(abs(aa),abs(bb));
	else if (aa!=0) t=t=gcd(abs(bb),abs(aa));
	else t=1;
	aa=aa/t;
	bb=bb/t;
	cout<<aa<<'/'<<bb;
}

int main()
{ 
	int num;	// 分子
	int den;	// 分母

	// 依次输入分子、分母
	cin >> num >> den;

	Fraction z;
	z.assign( num, den );
	cout << "z = ";
	z.print();

	Flag flag;
	double val = z.convert(flag);

	switch(flag)
	{
	case NORMAL:
		cout << " = " << val << endl;
		break;
	case NAN:
		cout << " = #NAN" << endl;
		break;
	case INF:
		cout << " = #INF" << endl;
		break;
	default:
		break;
	}

	z.invert();
	cout << "1/z = "; 
	z.print();
	cout << endl;
	system("pause");
	return 0;
}
