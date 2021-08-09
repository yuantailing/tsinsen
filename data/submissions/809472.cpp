#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
struct node {
    int n;
    int minn;
};

node v[1 << 21];

inline node *parent(node *p) {
    if (p == v + 1) return 0;
    return v + ((p - v) >> 1);
}
inline node *lChild(node *p) {
    if (p - v >= 1 << 20) return 0;
    return v + ((p - v) << 1);
}
inline node *rChild(node *p) {
    if (p - v >= 1 << 20) return 0;
    return v + ((p - v) << 1) + 1;
}

template <typename T> inline T myMin(T a, T b) {
    return a > b ? b : a;
}

bool borrow(int d, int s, int t) {
    int lo = 0, hi = 1 << 20;
    node *hot = v + 1;
    if (s == t) {
        while (1) {
            if (hi - lo == 1) break;
            int mid = (hi + lo) >> 1;
            if (s < mid) {
                hi = mid;
                hot = lChild(hot);
            } else {
                lo = mid;
                hot = rChild(hot);
            }
        }
        hot->n -= d;
        while (parent(hot)) {
            hot = parent(hot);
            node *lc = lChild(hot);
            node *rc = rChild(hot);
            hot->minn = myMin(lc->minn + lc->n, rc->minn + rc->n);
            if (hot->minn < 0) return false;
        }
        return true;
    }
    while (1) {
        int mid = (hi + lo) >> 1;
        if (s < mid && t >= mid) break;
        if (s < mid) {
            hi = mid;
            hot = lChild(hot);
        } else {
            lo = mid;
            hot = rChild(hot);
        }
    }
    node *branch = hot;
    int loSave = lo;
    int hiSave = hi;
    hot = lChild(branch);
    hi = (loSave + hiSave) >> 1;
    while (1) {
        if (hi - lo == 1) {
            hot->n -= d;
            break;
        }
        int mid = (hi + lo) >> 1;
        if (s < mid) {
            hi = mid;
            rChild(hot)->n -= d;
            hot = lChild(hot);
        } else {
            lo = mid;
            hot = rChild(hot);
        }
    }
    while (parent(hot) != branch) {
        hot = parent(hot);
        node *lc = lChild(hot);
        node *rc = rChild(hot);
        hot->minn = myMin(lc->minn + lc->n, rc->minn + rc->n);
        if (hot->minn < 0) return false;
    }
    hot = rChild(branch);
    lo = (loSave + hiSave) >> 1;
    hi = hiSave;
    while (1) {
        if (hi - lo == 1) {
            hot->n -= d;
            break;
        }
        int mid = (hi + lo) >> 1;
        if (t < mid) {
            hi = mid;
            hot = lChild(hot);
        } else {
            lo = mid;
            lChild(hot)->n -= d;
            hot = rChild(hot);
        }
    }
    while (parent(hot)) {
        hot = parent(hot);
        node *lc = lChild(hot);
        node *rc = rChild(hot);
        hot->minn = myMin(lc->minn + lc->n, rc->minn + rc->n);
        if (hot->minn < 0) return false;
    }
    return true;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[(1 << 20) + i].n);
    for (node *p = &v[(1 << 20) - 1]; p != v; p--) {
        node *lc = lChild(p);
        node *rc = rChild(p);
        p->minn = myMin(lc->n + lc->minn, rc->n + rc->minn);
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
