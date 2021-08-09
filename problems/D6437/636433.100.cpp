#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n, m, p;
    cin >> n >> m >> p;
    int np = 1;
    int mp = 1;
    while (n) {
        np *= n--;
        np %= p;
    }
    while (m) {
        mp *= m--;
        mp %= p;
    }
    cout << (np - mp + p) % p;
    return 0;
}
