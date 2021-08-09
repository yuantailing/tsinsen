#include <iostream>
using namespace std;

long long C(int a, int b) {
    long long x = 1, y = 1;
    for (int i = a; i > a - b; i--)
        x *= i;
    for (int i = 1; i <= b; i++)
        y *= i;
    return x / y;
}

long long Pow(int x, int a) {
    long long ans = 1;
    for (int i = 0; i < a; i++) {
        ans *= x;
        if (ans > 10007)
            ans %= 10007;
    }
    return ans;
}

int main() {
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    cout << (Pow(a, n) * Pow(b, m) * C(k, n)) % 10007;
    return 0;
}
