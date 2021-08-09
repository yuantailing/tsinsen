#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int a[20][20];

int f(int m, int n) {
    if (m < n) return 0;
    if (!n) return 1;
    if (a[m][n]) return a[m][n];
    return a[m][n] = f(m-1,n)+f(m,n-1);
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << f(m, n);
    return 0;
}
