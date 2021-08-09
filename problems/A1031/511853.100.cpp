#include <iostream>
using namespace std;
int main(){
	int i, j;
	for (i = 1; i <= 15; ++i)
	{
		for (j = i; j > 1; --j)
			cout << (char)('A' + j - 1);
		for (j = 1; j <= i; ++j)
			cout << (char)('A' + j - 1);
		cout << endl;
	}
	return 0;
}
