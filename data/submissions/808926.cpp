#include <iostream>
using namespace std;

int w[200000], v[200000];
int L[200000], R[200000];
long long sumC[200000], sumS[200000];
int n, m;
long long S;
long long S2;

long long y[1000002];
long long Y(int W) {
    if (y[W] != -1)
        return y[W];
    if (w[0] >= W) {
        sumC[0] = 1;
        sumS[0] = v[0];
    } else {
        sumC[0] = 0;
        sumS[0] = 0;
    }
    int tC = sumC[0];
    int tS = sumS[0];
    for (int i = 1; i < n; i++) {
        if (w[i] >= W) {
            sumC[i] = tC + 1;
            tC = sumC[i];
            sumS[i] = tS + v[i];
            tS = sumS[i];
        } else {
            sumC[i] = tC;
            sumS[i] = tS;
        }
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long deltaC = sumC[R[i]];
        long long deltaS = sumS[R[i]];
        if (L[i] > 0) {
            deltaC -= sumC[L[i] - 1];
            deltaS -= sumS[L[i] - 1];
        }
        ans += deltaC * deltaS;
        if (ans > S2) return ans;
    }
    return y[W] = ans;
}

long long llAbs(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    for (int i = 0; i < 1000002; i++)
        y[i] = -1;
    cin >> n >> m >> S;
    S2 = S << 1;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
        if (w[i] >= r)
            r = w[i] + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
    }
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
    cout << theMin << endl;
    return 0;
}
