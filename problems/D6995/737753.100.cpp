#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int f(int n, bool flag) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (flag)
        return f(n-2, false) + f(n-3, false);
    else
        return f(n-1, true) + f(n-2, false) + f(n-3, false);
}

int g(int n, bool flag) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (flag)
        return g(n-2, false) + g(n-3, false);
    else
        return g(n-1, true) + g(n-2, false) + g(n-3, false) + f(n-1, true);
}

int main() {
    int N;
    cin >> N;
    cout << f(N, false) << endl << g(N, false);
    return 0;
}
