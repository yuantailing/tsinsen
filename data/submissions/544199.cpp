#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <assert.h>
using namespace std;

class Point
{
	public:
		// 请补充
	int x,y,z;
	Point(int xx, int yy, int zz){
		x=xx;y=yy;z=zz;}
	void negate(){
		x=-x;y=-y;z=-z;}
	double dist(){
		return sqrt(x*x+y*y+z*z);}
		
	void print() const
	{
		cout << "(" << x << ", " << y << ", " << z << ")";
	}
};
int main()
{ 
	int x, y, z;
		
	// 请输入将要赋予Point类实例的三个坐标分量( x, y, z )
	cin >> x >> y >> z;

	Point p( x, y, z );
  	cout << "p = ";
  	p.print();
  	cout << ", p.dist() = " << p.dist() << endl;
  	
	p.negate();
	cout << "p = ";
  	p.print();
  	cout << ", p.dist() = " << p.dist() << endl;
  	
	return 0;
}
