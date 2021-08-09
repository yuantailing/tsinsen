#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool isPrime(int x) {
    if (x == 2) return true;
    for (int i = 3; i * i <= x; i+=2) {
        if (x % i == 0) return false;
    }
    return true;
}
int *pr = new int[300];

int deal(int n) {
    static int *dealv = new int[100001];
    if (n < 4) return 0;
    if (dealv[n]) return dealv[n];
    int t = 0;
    int m = 0;
    while (pr[t] * pr[t] <= n) {
        if (n % pr[t] == 0) {
            int x = pr[t] + deal(n - 2 * pr[t]);
            if (x > m)
                m = x;
        }
        t++;
    }
    return dealv[n] = m;
}

int main() {
    int t = 0;
    for (int i = 2; i <= 400; i++)
        if (isPrime(i))
            pr[t++] = i;
    int N;
    cin >> N;
    cout << deal(N);
    return 0;
}
