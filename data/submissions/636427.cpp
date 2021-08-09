#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n, p = 1;
    long long ans = 1;
    int len;
    cin >> n >> len;
    char format[100];
    sprintf(format, "%%0%dd", len);
    while (len--)
        p *= 10;
    for (long long i = 1; i <= n; i++) {
        ans *= i;
        ans %= p;
    }
    printf(format, (int)ans);
    return 0;
}
