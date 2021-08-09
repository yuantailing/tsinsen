#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

long long a, b, p, m;

long long f(long long n) {
    if (!n) return a;
    if (n == 1) return b;
    return (f(n/2) + f(n/3)) % m;
}

int main() {
    cin >> a >> b >> p >> m;
    cout << f(p);
    return 0;
}
