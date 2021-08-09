#include <iostream>
#include <cassert>
using namespace std;
class zrf_Ratio
{
	friend std::ostream& operator<<(std::ostream&, const zrf_Ratio&);
	friend std::istream& operator>>(std::istream&, zrf_Ratio&);
public:
	zrf_Ratio(int=0,int=1);
	zrf_Ratio(const zrf_Ratio&);
	zrf_Ratio& operator=(const zrf_Ratio&);
	zrf_Ratio& operator*=(const zrf_Ratio&);
	zrf_Ratio operator++();
	zrf_Ratio operator++(int);
	int& operator[](int);
private:
	int num;
	int den;
	void reduce();
};
zrf_Ratio& zrf_Ratio::operator=(const zrf_Ratio&b)
{
	num=b.num;
	den=b.den;
	reduce();
	return *this;
}
zrf_Ratio& zrf_Ratio::operator*=(const zrf_Ratio&b)
{
	num*=b.num;
	den*=b.den;
	reduce();
	return *this;
}
zrf_Ratio zrf_Ratio::operator++()
{
	num+=den;
	reduce();
	return *this;
}
zrf_Ratio zrf_Ratio::operator++(int)
{
	zrf_Ratio old(*this);
	++(*this);
	return old;
}
int& zrf_Ratio::operator[](int x)
{
	if (x==1) return num;
	else return den;
}
std::ostream& operator<<(std::ostream&ost, const zrf_Ratio&a)
{
	ost<<a.num<<"/"<<a.den;
	return ost;
}
std::istream& operator>>(std::istream&ist, zrf_Ratio&a)
{
	ist>>a.num>>a.den;
	a.reduce();
	return ist;
}
//公有成员函数:
zrf_Ratio::zrf_Ratio(int num, int den) : num(num), den(den){ reduce();}
zrf_Ratio::zrf_Ratio(const zrf_Ratio& r) : num(r.num), den(r.den){ }
//私有成员函数:
void swap(int &m, int &n)
{
	int t;
	t=m;
	m=n;
	n=t;
}
int zrf_Gcd(int m, int n)
{
	if (m<n)
		swap(m,n);
	assert(n>=0);
	while (n>0)
	{
		int r=m%n;
		m = n;
		n = r;
	}
	return m;
}
void zrf_Ratio::reduce()
{
	if (num == 0 || den == 0)
	{
		num = 0;
		den = 1;
		return;
	}
	if (den < 0)
	{
		den *= -1;
		num *= -1;
	}
	if (num == 1)
		return;
	int sgn = (num<0?-1:1);
	int g = zrf_Gcd(sgn*num,den);
	num /= g;
	den /= g;
}
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	cin >> a >> b >> c >> d;
	zrf_Ratio zrf(a,b),ssh(c,d),zl;
	zl=zrf;
	std::cout<<"zrf is:"<<zrf<<"; ssh is:"<<ssh<<'\n' ;
	std::cout<<"zl is:"<<zl << endl;
	std::cout<<"After zrf*=ssh, zrf is:"<<zrf <<endl;
	std::cout<<"After zrf++ is:"<<zrf++ <<endl;
	std::cout<<"After ++zrf is:"<<++zrf <<endl;
	std::cout<<"zrf[1] is:"<<zrf[1]<<"; zrf[2] is:"<<zrf[2] <<endl;
	return 0;
}
