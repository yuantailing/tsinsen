#include <iostream>
using namespace std;

struct node {
    int l;
    int r;
};

node king;
node p[1000];
int n;
bool choose[1000];
long long maxn = -1;
long long get[1000];

void dfs(int k, long long by) {
    if (k == n) {
        int t = -1;
        for (int i = 0; i < n; i++) {
            if (get[i] > t)
                t = get[i];
        }
        if (maxn == -1 || t < maxn)
            maxn = t;
        return;
    }
    int minR = -1;
    for (int i = 0; i < n; i++) {
        if (choose[i]) continue;
        if (minR == -1 || p[i].r < minR) minR = p[i].r;
    }
    if (maxn != -1 && by / minR > maxn) return;
    for (int i = 0; i < n; i++) {
        if (choose[i]) continue;
        if (maxn != -1 && by / p[i].r > maxn) continue;
        choose[i] = true;
        get[k] = by / p[i].r;
        dfs(k + 1, by * (long long)p[i].l);
        choose[i] = false;
    }
}

int main() {
    cin >> n;
    cin >> king.l >> king.r;
    for (int i = 0; i < n; i++)
        cin >> p[i].l >> p[i].r;
    dfs(0, king.l);
    cout << maxn << endl;
    return 0;
}
