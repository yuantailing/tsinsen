#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

int gcd(int a, int b){
	if (a % b == 0) return b;
	else return (gcd(b, a % b));
}
int f(int x, int y, int z){
	switch (z){
		case 1: return x + y;
		case 2: return x - y;
		case 3: return x * y;
		case 4: return x / y;
		case 5: return x % y;
		case 6: return gcd(x, y);
		case 7: return x * y / gcd(x, y);
		default: return 0;
	};
}
int main(){
	int i, j, k;
	int x, y, z;
	cin >> x >> y >> z;
	cout << f(x,y,z);
	//system("pause");
	return 0;
}
