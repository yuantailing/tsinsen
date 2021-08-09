#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n, p = 1;
    long long ans = 1;
    int len;
    cin >> n >> len;
    int _len = len;
    while (_len--)
        p *= 10;
    for (long long i = 1; i <= n; i++) {
        ans *= i;
        ans %= p;
    }
    int digit = 0;
    long long _ans = ans;
    while (_ans /= 10)
        digit++;
    for (int i = digit + 1; i < len; i++)
        cout << '0';
    cout << ans;
    return 0;
}
