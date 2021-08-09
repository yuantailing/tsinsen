#include <iostream>
using namespace std;

long long C(int a, int b) {
    int *v1 = new int[a + 1];
    int *v2 = new int[a + 1];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j < i; j++)
            v2[j] = v1[j];
        for (int j = 1; j < i; j++)
            v1[j] = (v2[j - 1] + v2[j]) % 10007;
        v1[0] = v1[i] = 1;
    }
    long long ans = v1[b] % 10007;
    delete[] v1;
    delete[] v2;
    return ans;
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
