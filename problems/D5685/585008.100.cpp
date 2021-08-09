#include <iostream>
#include <cassert>
using namespace std;
class zrf_Ratio
{
	friend std::ostream& operator<<(std::ostream&, const zrf_Ratio&);
	friend std::istream& operator>>(std::istream&, zrf_Ratio&);
	friend bool operator==(const zrf_Ratio&, const zrf_Ratio&);
	friend bool operator<(const zrf_Ratio&, const zrf_Ratio&);
public:
	zrf_Ratio(int=0,int=1);
	zrf_Ratio(const zrf_Ratio&);
private:
	int num;
	int den;
	void reduce();//化为最简分数
};
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

bool operator==(const zrf_Ratio & a, const zrf_Ratio & b)
{
	return a.num*b.den==a.den*b.num;
}

bool operator<(const zrf_Ratio & a, const zrf_Ratio & b)
{
	if (a==b) return false;
	else return (double)a.num/a.den<(double)b.num/b.den;
}
//公有成员函数:
zrf_Ratio::zrf_Ratio(int num, int den) : num(num), den(den)
{
	reduce();
}
zrf_Ratio::zrf_Ratio(const zrf_Ratio& r) : num(r.num), den(r.den)
{
}
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
	zrf_Ratio zrf(a, b),ssh(c, d);
	std::cout<<"zrf is:"<<zrf<<"; ssh is:"<<ssh<<'\n' ;
	std::cout<<"(zrf==ssh) is:"<<(zrf==ssh)<<"; (zrf<ssh) is:"<<(zrf<ssh) <<endl;
	return 0;
}
