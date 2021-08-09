#include <iostream>
using namespace std;
class Base1
{
public:
	Base1(int n){cout << "Base1 constructor called " << n << endl;}
	~Base1(){cout << "Base1 destructor called" << endl;}
};
class Base2
{
public:
	Base2(int n){cout << "Base2 constructor called " << n << endl;}
	~Base2(){cout << "Base2 destructor called" << endl;}
};
class Base3
{
public:
	Base3(int n){cout << "Base3 constructor called " << n << endl;}
	~Base3(){cout << "Base3 destructor called" << endl;}
};
class Derived:public Base2,public Base1,public Base3
{
	Base3 member3; Base1 member1; Base2 member2;
public:
	Derived(int a, int b, int c, int d, int e, int f, int g):
	  Base1(b), Base2(c), Base3(d), member1(e), member2(f), member3(g)
	  {
		  cout << "Derived constructor called " << a << endl;
	  }
	  ~Derived(){cout << "Derived destructor called" << endl;}
};
int main()
{
	Derived objD(1,2,3,4,5,6,7);
	return 0;
}
