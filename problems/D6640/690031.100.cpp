#include <iostream>
using namespace std;

int main()
{
    int s, t, a, b, c, d;
    int A[10001], B[10001], C[10001], D[10001];
    cin >> s >> t;
    cin >> a >> b >> c >> d;
    //Fib(1) = Fib(2) = 1
    A[1] = 1%a;
    A[2] = 1%a;
    B[1] = 1%b;
    B[2] = 1%b;
    C[1] = 1%c;
    C[2] = 1%c;
    D[1] = 1%d;
    D[2] = 1%d;
    for (int i = 1; i <= t; i++) {
        A[i+2] = (A[i+1]+A[i])%a;
        B[i+2] = (B[i+1]+B[i])%b;
        C[i+2] = (C[i+1]+C[i])%c;
        D[i+2] = (D[i+1]+D[i])%d;
    }
    for (int j = s; j <= t; j++)
        if (A[j] && B[j] && C[j] && D[j])
            cout << j << ' ';
    return 0;
}
