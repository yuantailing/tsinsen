#include <iostream>
using namespace std;

int w[200000], v[200000];
int L[200000], R[200000];
int n, m;
long long S;


long long y[1000001];
long long Y(int W) {
    if (y[W] != -1)
        return y[W];
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long count = 0, sum = 0;
        for (int j = L[i]; j <= R[i]; j++)
            if (w[j] > W) {
                count++;
                sum += v[j];
            }
        ans += count * sum;
    }
    return y[W] = ans;
}

long long llAbs(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    for (int i = 0; i < 107; i++)
        y[i] = -1;
    cin >> n >> m >> S;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
    }
    int l = 0, r = 1e6;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (Y(mid) > S) l = mid;
        else r = mid;
    }
    long long theMin = llAbs(Y(r) - S);
    for (int i = l; i < r; i++) {
        if (llAbs(Y(i) - S) < theMin)
            theMin = llAbs(Y(i) - S);
    }
    //for (int i = 0; i < 8; i++)
    //    printf("Y(%d) = %lld\n", i, Y(i));
    cout << theMin << endl;
    return 0;
}
