#include <iostream>
using namespace std;

int N, K;

int **v;

long long solve(int n, int k) {
    if (k == 0) return 1;
    if (k + k > n + 1) return 0;
    if (v[n][k] != -1) return v[n][k];
    return v[n][k] = (solve(n - 1, k) + solve(n - 2, k - 1)) % 1007;
}

int main() {
    cin >> N >> K;
    v = new int *[N + 1];
    for (int i = 0; i <= N; i++) {
        v[i] = new int[K + 1];
        for (int j = 0; j <= K; j++)
            v[i][j] = -1;
    }
    cout << solve(N, K) << endl;
    return 0;
}
