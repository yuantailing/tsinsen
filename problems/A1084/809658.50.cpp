#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef struct {
    double real;
    double img;
} COMPLEX;

double const pi=3.1415926535897932384626;

int n;
COMPLEX x[16390];
COMPLEX w;
COMPLEX fy;

void By(COMPLEX &c, COMPLEX const &a, COMPLEX const &b) {
    double d=a.real*b.real-a.img*b.img;
    c.img=a.real*b.img+a.img*b.real;
    c.real=d;
}
void Add(COMPLEX &c, COMPLEX const &a, COMPLEX const &b) {
    double d=a.real+b.real;
    c.img=a.img+b.img;
    c.real=d;
}
void Print(COMPLEX const &c) {
    printf("%.2lf %.2lf\n",c.real/n,c.img/n);
}

COMPLEX Fourier(int i, int start, int step, int n, COMPLEX w, COMPLEX wi) {
    if (start + step >= n)
        return x[start];
    COMPLEX w2;
    By(w2, w, w);
    COMPLEX wi2;
    By(wi2, wi, wi);
    COMPLEX pi = Fourier(i, start, step << 1, n, w2, wi2);
    COMPLEX qi = Fourier(i, start + step, step << 1, n, w2, wi2);
    COMPLEX ret;
    By(ret, wi, qi);
    Add(ret, pi, ret);
    return ret;
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>x[i].real>>x[i].img;
    w.real=cos(2*pi/n);
    w.img=sin(2*pi/n);
    COMPLEX wi;
    wi.real = 1;
    wi.img = 0;
    for (int i = 0; i < n; i++) {
        COMPLEX t = Fourier(i, 0, 1, n, w, wi);
        Print(t);
        By(wi, wi, w);
    }
    return 0;
}
