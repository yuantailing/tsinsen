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
public:
	static int count;
	Width(){++count;}
	~Width(){--count;}
};
int Width::count=0;

	int main()
	{  
		Width w, x;
		cout << "#objects = " << w.count << endl;
		{ 
			Width w, x, y, z;
			cout << "#objects = " << w.count << endl;
		}
		cout << "#objects = " << w.count << endl;

		Width y;
		cout << "#objects = " << w.count << endl;

		return 0;
	}
