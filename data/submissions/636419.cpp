#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n, p;
    long long ans = 1;
    cin >> n >> p;
    for (long long i = 1; i <= n; i++) {
        ans *= i;
        ans %= p;
    }
    cout << ans;
    return 0;
}
