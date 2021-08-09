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
	int numWidths(){return count;}
};
int Width::count=0;

int main( int argc, char * argv[] )
{ 
	Width w, x;
	cout << "#objects = " << w.numWidths() << endl;
	{ 
		Width w, x, y, z;
		cout << "#objects = " << w.numWidths() << endl;
	}
	cout << "#objects = " << w.numWidths() << endl;
	Width y;
	cout << "#objects = " << w.numWidths() << endl;
	return 0;
}
