#include <iostream>
using namespace std;

int N, K;

long long solve(int n, int k) {
    if (k == 0) return 1;
    if (k + k > n + 1) return 0;
    return (solve(n - 1, k) + solve(n - 2, k - 1)) % 1007;
}

int main() {
    cin >> N >> K;
    cout << solve(N, K) << endl;
    return 0;
}
