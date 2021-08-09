#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int go(int n) {
    if (n < 1) return 0;
    static int v[128];
    if (v[n]) return v[n];
    if (n <= 3)
        return v[n] = 1 + go(n-1) + go(n-2) + go(n-3);
    return v[n] = go(n-1) + go(n-2) + go(n-3);
}

int main() {
    int h;
    cin >> h;
    if (4 <= h && h <= 20)
        cout << go(h);
    else
        cout << 0;
    return 0;
}
