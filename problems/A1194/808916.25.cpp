#include <iostream>
using namespace std;

int w[200000], v[200000];
int L[200000], R[200000];
long long sumC[200000], sumS[200000];
int n, m;
long long S;


long long y[1000002];
long long Y(int W) {
    /*if (y[W] != -1)
        return y[W];
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        long long count = 0, sum = 0;
        for (int j = L[i]; j <= R[i]; j++)
            if (w[j] >= W) {
                count++;
                sum += v[j];
            }
        ans += count * sum;
    }
    return y[W] = ans;*/
    if (y[W] != -1)
        return y[W];
    if (w[0] > W) {
        sumC[0] = 1;
        sumS[0] = v[0];
    } else {
        sumC[0] = 0;
        sumS[0] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (w[i] > W) {
            sumC[i] = sumC[i - 1] + 1;
            sumS[i] = sumS[i - 1] + v[i];
        } else {
            sumC[i] = sumC[i - 1];
            sumS[i] = sumS[i - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        long long deltaC = L[i] > 0 ? sumC[R[i]] - sumC[L[i] - 1] : sumC[R[i]];
        long long deltaS = L[i] > 0 ? sumS[R[i]] - sumS[L[i] - 1] : sumS[R[i]];
        ans += deltaC * deltaS;
    }
    return ans;
}

long long llAbs(long long x) {
    return x < 0 ? -x : x;
}

int main() {
    for (int i = 0; i < 1000002; i++)
        y[i] = -1;
    cin >> n >> m >> S;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
    for (int i = 0; i < m; i++) {
        cin >> L[i] >> R[i];
        L[i]--, R[i]--;
    }
    int l = 0, r = 1000001;
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
