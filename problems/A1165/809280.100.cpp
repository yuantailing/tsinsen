#include <iostream>
using namespace std;

int n, m;

long long f[31][31];
long long F(int times, int person) {
    if (f[times][person] >= 0) return f[times][person];
    return f[times][person] = F(times - 1, person == 0 ? n - 1 : person - 1) + F(times - 1, person == n - 1 ? 0 : person + 1);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = -1;
    for (int i = 1; i < n; i++)
        f[0][i] = 0;
    f[0][0] = 1;
    cout << F(m, 0);
    return 0;
}
