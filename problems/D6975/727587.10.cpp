#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int a, b, p, m;

int f(int n) {
    if (!n) return a;
    if (n == 1) return b;
    return (f(n/2) + f(n/3)) % m;
}

int main() {
    cin >> a >> b >> p >> m;
    cout << f(p);
    return 0;
}
