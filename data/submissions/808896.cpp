#include <iostream>
using namespace std;

long long C(int a, int b) {
    if (a == b || b == 0) return 1;
    return (C(a - 1, b) + C(a - 1, b - 1)) % 10007;
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
