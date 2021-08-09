#include <iostream>
#include <cstdio>
using namespace std;

class INT {
public:
    INT() { d = 1; v[0] = 0; v[1] = 0; }
    INT(int t) { d = 1; v[0] = t; v[1] = 0; }
    INT &operator =(int t) { d = 1; v[0] = t; v[1] = 0; return *this; }
    INT &operator =(INT const &t) { d = t.d; for (int i = 0; i <= d; i++) v[i] = t.v[i]; return *this; }
    INT operator *(int t);
    INT operator +(INT const &t);
    bool operator ==(INT const &t);
    bool operator >(INT const &t);
    void print() const ;
    friend ostream & operator <<(ostream &os, INT const &t);
public:
    int d;
    int v[11];
};

bool INT::operator ==(INT const &t) {
    if (d != t.d) return false;
    for (int i = d - 1; i >= 0; i--)
        if (v[i] != t.v[i])
            return false;
    return v[0] == t.v[0];
}

bool INT::operator >(INT const &t) {
    if (d != t.d) return d > t.d;
    for (int i = d - 1; i >= 0; i--)
        if (v[i] != t.v[i])
            return v[i] > t.v[i];
    return v[0] > t.v[0];
}

INT INT::operator *(int t) {
    if (t == 0) {
        return INT(0);
    }
    v[d] = 0;
    INT r(0);
    r = *this;
    for (int i = 0; i < r.d; i++)
        r.v[i] *= t;
    for (int i = 0; i < r.d; i++) {
        r.v[i + 1] += r.v[i] / 10000;
        r.v[i] %= 10000;
    }
    while (r.v[r.d] > 0) {
        r.v[r.d + 1] = r.v[r.d] / 10000;
        r.v[r.d] %= 10000;
        r.d++;
    }
    r.v[r.d] = 0;
    return r;
}

INT INT::operator +(INT const &t) {
    INT r(0);
    int mn = d > t.d ? d : t.d;
    for (int i = 0; i < mn; i++) {
        r.v[i] += (d > i ? v[i] : 0) + (t.d > i ? t.v[i] : 0);
        if (r.v[i] >= 10000) {
            r.v[i] -= 10000;
            r.v[i + 1] = 1;
        } else
            r.v[i + 1] = 0;
    }
    r.d = mn;
    if (r.v[r.d] != 0) {
        r.d++;
        r.v[r.d] = 0;
    }
    return r;
}

void INT::print() const {
    printf("%d", v[d - 1]);
    for (int i = d - 2; i >= 0; i--)
        printf("%04d", v[i]);
}

ostream & operator <<(ostream &os, INT const &t) {
    t.print();
    return os;
}

int n, m;
int a[80];

INT p[81];

INT f[80][80];
INT F(int l, int r) {
    if (l < 0 || r >= m || l > r) return INT(0);
    if (!(f[l][r] == INT(-1))) return f[l][r];
    INT ret1(0);
    INT ret2(0);
    ret1 = p[m - (r - l)] * a[l] + F(l + 1, r);
    ret2 = p[m - (r - l)] * a[r] + F(l, r - 1);
    return f[l][r] = (ret1 > ret2 ? ret1 : ret2);
}

int main() {
    p[0] = INT(1);
    for (int i = 1; i <= 80; i++)
        p[i] = p[i - 1] * 2;
    cin >> n >> m;
    INT sum(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> a[j];
        for (int j = 0; j < m; j++)
            for (int k = j; k < m; k++)
                f[j][k] = INT(-1);
        sum = sum + F(0, m - 1);
    }
    cout << sum << endl;
    return 0;
}
