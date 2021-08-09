#include <iostream>
#include <cstdio>
using namespace std;

int myMod(int a, int b) {
    return a % b >= 0 ? a % b : a % b + (b > 0 ? b : -b);
}

int myDiv(int a, int b) {
    return (a - myMod(a, b)) / b;
    return a / b;
}

int main() {
    int N, R;
    scanf("%d%d", &N, &R);
    int a[100];
    int d = 0;
    int nCopy = N;
    while (nCopy) {
        a[d] = myMod(nCopy, R);
        nCopy = myDiv(nCopy, R);
        d++;
    }
    printf("%d=", N);
    d--;
    while (d >= 0) {
        putchar(a[d] >= 10 ? 'A' + a[d] - 10 : '0' + a[d]);
        d--;
    }
    printf("(base%d)\n", R);
    return 0;
}
