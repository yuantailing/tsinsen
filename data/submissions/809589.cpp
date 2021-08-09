#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
struct node {
    int n;
    int minn;
} v[1 << 21];

template <typename T> inline T myMin(T a, T b) {
    return a > b ? b : a;
}

bool borrow(int d, int s, int t) {
    int lo = 0, hi = 1 << 20;
    int hot = 1;
    if (s == t) {
        while (1) {
            if (hi - lo == 1) break;
            int mid = (hi + lo) >> 1;
            if (s < mid) {
                hi = mid;
                hot <<= 1;
            } else {
                lo = mid;
                hot = (hot << 1) | 1;
            }
        }
        v[hot].n -= d;
        while (hot != 1) {
            hot >>= 1;
            int lc = hot << 1;
            int rc = lc | 1;
            v[hot].minn = myMin(v[lc].minn + v[lc].n, v[rc].minn + v[rc].n);
            if (v[hot].minn < 0) return false;
        }
        return true;
    }
    while (1) {
        int mid = (hi + lo) >> 1;
        if (s < mid) {
            if (t >= mid) break;
            hi = mid;
            hot <<= 1;
        } else {
            lo = mid;
            hot = (hot << 1) | 1;
        }
    }
    int branch = hot;
    int loSave = lo;
    int hiSave = hi;
    hot = branch << 1;
    hi = (loSave + hiSave) >> 1;
    while (1) {
        if (hi - lo == 1) {
            v[hot].n -= d;
            break;
        }
        int mid = (hi + lo) >> 1;
        if (s < mid) {
            hi = mid;
            hot <<= 1;
            v[hot | 1].n -= d;
        } else {
            lo = mid;
            hot = (hot << 1) | 1;
        }
    }
    hot >>= 1;
    while (hot != branch) {
        int lc = hot << 1;
        int rc = lc | 1;
        v[hot].minn = myMin(v[lc].minn + v[lc].n, v[rc].minn + v[rc].n);
        if (v[hot].minn < 0) return false;
        hot >>= 1;
    }
    hot = (branch << 1) | 1;
    lo = (loSave + hiSave) >> 1;
    hi = hiSave;
    while (1) {
        if (hi - lo == 1) {
            v[hot].n -= d;
            break;
        }
        int mid = (hi + lo) >> 1;
        if (t < mid) {
            hi = mid;
            hot <<= 1;
        } else {
            lo = mid;
            hot = (hot << 1) | 1;
            v[hot - 1].n -= d;
        }
    }
    hot >>= 1;
    while (hot != branch) {
        int lc = hot << 1;
        int rc = lc | 1;
        v[hot].minn = myMin(v[lc].minn + v[lc].n, v[rc].minn + v[rc].n);
        if (v[hot].minn < 0) return false;
        hot >>= 1;
    }
    while (hot) {
        int lc = hot << 1;
        int rc = lc | 1;
        int save = v[hot].minn;
        v[hot].minn = myMin(v[lc].minn + v[lc].n, v[rc].minn + v[rc].n);
        if (v[hot].minn < 0) return false;
        if (v[hot].minn == save) break;
        hot >>= 1;
    }
    return true;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[(1 << 20) + i].n);
    for (int p = (1 << 20) - 1; p; p--) {
        int lc = p << 1;
        int rc = lc | 1;
        v[p].minn = myMin(v[lc].n + v[lc].minn, v[rc].n + v[rc].minn);
    }
    for (int i = 1; i <= m; i++) {
        int d, s, t;
        scanf("%d%d%d", &d, &s, &t);
        if (!borrow(d, s, t)) {
            printf("-1\n%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
