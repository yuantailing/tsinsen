#include <iostream>
#include <cstdio>
using namespace std;

struct node {
    int l;
    int r;
};
/*
class INT {
public:
    INT(int t) : x(t) { }
    void operator=(int t) { x = t; }
    void operator=(INT const &t) { x = t.x; }
    INT operator*(int t) { INT r(t); r.x *= x; return r; }
    INT operator/(int t) { INT r(0); r.x = x / t; return r; }
    bool operator>(INT const &t) { return x > t.x; }
    void print() { cout << x; }
public:
    long long x;
};
*/

class INT {
public:
    INT(int t) { d = 1; v[0] = t; v[1] = 0;}
    void operator =(int t) { d = 1; v[0] = t; v[1] = 0;}
    void operator =(INT const &t) { d = t.d; for (int i = 0; i <= d; i++) v[i] = t.v[i]; }
    INT operator *(int t);
    INT operator /(int t);
    bool operator >(INT const &t);
    void print() const ;
    friend ostream & operator <<(ostream &os, INT const &t);
public:
    int d;
    int v[1008];
};

bool INT::operator >(INT const &t) {
    if (d != t.d) return d > t.d;
    for (int i = d - 1; i >= 0; i--)
        if (v[i] != t.v[i])
            return v[i] > t.v[i];
    return v[0] > t.v[0];
}

INT INT::operator *(int t) {
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

INT INT::operator /(int t) {
    INT r(0);
    r = *this;
    for (int i = r.d - 1; i >= 0; i--) {
        if (i > 0) r.v[i - 1] += 10000 * (r.v[i] % t);
        r.v[i] /= t;
    }
    while (r.d > 1 && !r.v[r.d - 1]) r.d--;
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

//typedef long long INT;
node king;
node p[1000];
int by[1000];
int n;
INT maxn = 0;
int main() {
    /*INT yy(1);
    for (int i = 1; i < 20; i++) {
        yy = yy * 100;
        yy.print();
        cout << endl;
        yy = yy / 20;
        yy.print();
        cout << endl;
    }*/
    cin >> n;
    cin >> king.l >> king.r;
    for (int i = 0; i < n; i++) {
        cin >> p[i].l >> p[i].r;
        by[i] = p[i].l * p[i].r;
    }
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (by[i] > by[j]) {
                int t = by[i];
                by[i] = by[j];
                by[j] = t;
                node n = p[i];
                p[i] = p[j];
                p[j] = n;
            }
    INT x = king.l;
    for (int i = 0; i < n; i++) {
        if (x / p[i].r > maxn)
            maxn = x / p[i].r;
        x = x * p[i].l;
    }
    cout << maxn << endl;
    return 0;
}
