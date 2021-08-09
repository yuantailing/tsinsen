#include <iostream>
#include <cstdio>
using namespace std;

typedef int INT;

int N, K;
char a[40];
INT num[40][40];

INT f[40][7];
INT F(int pos, int kUsed) {
    if (kUsed == 0) return num[0][pos];
    if (f[pos][kUsed] != INT(-1)) return f[pos][kUsed];
    INT ret(0);
    for (int i = 0; i < pos; i++) {
        INT t = F(i, kUsed - 1) * num[i + 1][pos];
        if (t > ret) ret = t;
    }
    return f[pos][kUsed] = ret;
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
        while (a[i] < '0' || a[i] > '9')
            scanf("%c", a + i);
        a[i] -= '0';
    }
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (i == j) num[i][j] = INT(a[j]);
            else num[i][j] = num[i][j - 1] * 10 + INT(a[j]);
    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 7; j++)
            f[i][j] = INT(-1);
    cout << F(N - 1, K) << endl;
    return 0;
}
