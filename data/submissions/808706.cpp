#include <iostream>
#include <cstdlib>
using namespace std;

int N, M;

struct relationship {
    int a, b, c;
} *r;
int *p;

static int _cmp(void const *a, void const *b) {
    if (((relationship const*)a)->c > ((relationship const*)b)->c) return -1;
    if (((relationship const*)a)->c < ((relationship const*)b)->c) return 1;
    return 0;
}

int solve(int n) {
    if (n >= M) return n;
    int a = r[n].a;
    int b = r[n].b;
    if (p[a] != 0 && p[b] != 0) {
        if (p[a] == p[b]) return n;
        else return solve(n + 1);
    } else if (p[a] != 0) {
        p[b] = 3 - p[a];
        return solve(n + 1);
    } else if (p[b] != 0) {
        p[a] = 3 - p[b];
        return solve(n + 1);
    } else {
        p[a] = 1, p[b] = 2;
        int t1 = solve(n + 1);
        if (n) {
            p[a] = 2; p[b] = 1;
            int t2 = solve(n + 1);
            return t1 > t2 ? t1 : t2;
        } else
            return t1;
    }
}

int main() {
    cin >> N >> M;
    p = new int[N + 1];
    for (int i = 0; i <= N; i++)
        p[i] = 0;
    r = new relationship[M];
    for (int i = 0; i < M; i++)
        cin >> r[i].a >> r[i].b >> r[i].c;
    qsort(r, M, sizeof(relationship), &_cmp);
    int t = solve(0);
    if (t >= M) cout << 0;
    else cout << r[t].c;
    return 0;
}
