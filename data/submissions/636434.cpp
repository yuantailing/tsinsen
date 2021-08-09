#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int sign(double x) {
    static double const eps = 1e-10;
    return fabs(x)<eps ? 0 : x>0 ? 1 : -1;
}

int main()
{
    double x;
    cin >> x;
    cout << sign(x);
    return 0;
}
