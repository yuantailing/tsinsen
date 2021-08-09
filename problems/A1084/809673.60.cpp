#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct {
    double real;
    double img;
} COMPLEX;

double const pi = 3.1415926535897932384626;

int n;
COMPLEX x[16390];
COMPLEX w;

inline void By(COMPLEX &c, COMPLEX const &a, COMPLEX const &b) {
    double d = a.real * b.real - a.img * b.img;
    c.img = a.real * b.img + a.img * b.real;
    c.real = d;
}
inline void Add(COMPLEX &c, COMPLEX const &a, COMPLEX const &b) {
    double d=a.real+b.real;
    c.img=a.img+b.img;
    c.real=d;
}
inline void Print(COMPLEX const &c) {
    printf("%.2lf %.2lf\n",c.real/n,c.img/n);
}

COMPLEX const *Fourier(COMPLEX const *X, int n, COMPLEX w) {
    if (n == 1) {
        COMPLEX *ret = new COMPLEX[::n];
        for (int i = 0; i < ::n; i++)
            ret[i] = X[0];
        return ret;
    }
    COMPLEX *X1 = new COMPLEX[n / 2];
    COMPLEX *X2 = new COMPLEX[n / 2];
    for (int i = 0; i < n / 2; i++) {
        X1[i] = X[i * 2];
        X2[i] = X[i * 2 + 1];
    }
    COMPLEX w2;
    By(w2, w, w);
    COMPLEX const *P = Fourier(X1, n / 2, w2);
    COMPLEX const *Q = Fourier(X2, n / 2, w2);
    delete[] X1;
    delete[] X2;
    COMPLEX *ret = new COMPLEX[::n];
    COMPLEX wi;
    wi.real = 1;
    wi.img = 0;
    for (int i = 0; i < ::n; i++) {
        By(ret[i], wi, Q[i]);
        Add(ret[i], P[i], ret[i]);
        By(wi, wi, w);
    }
    delete[] P;
    delete[] Q;
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &x[i].real, &x[i].img);
    w.real = cos(2 * pi / n);
    w.img = sin(2 * pi / n);
    COMPLEX const *Y = Fourier(x, n, w);
    for (int i = 0; i < n; i++)
        Print(Y[i]);
    return 0;
}
