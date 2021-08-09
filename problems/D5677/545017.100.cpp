#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <assert.h>
using namespace std;

class Width
{
	// 请补充
	static int count;
public:
	Width(){++count;}
	~Width(){--count;}
	static int numWidths(){return count;}
};
int Width::count=0;

int main( int argc, char * argv[] )
{ 
	cout << "#objects = " << Width::numWidths() << endl;
	Width w, x;
	cout << "#objects = " << Width::numWidths() << endl;
	{ 
		Width w, x, y, z;
		cout << "#objects = " << Width::numWidths() << endl;
	}
	cout << "#objects = " << Width::numWidths() << endl;
	Width y;
	cout << "#objects = " << Width::numWidths() << endl;
	return 0;
}
