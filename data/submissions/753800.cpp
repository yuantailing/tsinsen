#include <iostream>
using namespace std;

int go(int n) {
    if (n < 1) return 0;
    if (n <= 3) return 1 + go(n-1) + go(n-2) + go(n-3);
    return go(n-1) + go(n-2) + go(n-3);
}

int main() {
    int h;
    cin >> h;
    cout << go(h);
    return 0;
}
