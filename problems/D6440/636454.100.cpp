#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int x) {
    static int primes[5] = {2, 3, 5, 7, 11};
    for (int i = 0; i < 5; i++)
        if (x == primes[i])
            return true;
    return false;
}

int main()
{
    int const maxSize = 13;
    int a[maxSize];
    for (int i = 1; i < maxSize; i++)
        a[i] = 0;
    a[0] = 1;
    for (int i = 0; i < 6; i++) {
        for (int j = maxSize; j > 0; j--)
            for (int k = 2; k > 0; k--)
                if (j >= k)
                    a[j] += a[j - k];
    }
    int ans = 0;
    int L, R;
    cin >> L >> R;
    for (int i = 0; i < maxSize; i++)
        if (i >= L && i <= R || isPrime(i))
            ans += a[i];
    cout << ans;
    return 0;
}
