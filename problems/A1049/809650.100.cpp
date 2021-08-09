#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    bool chong = true, mao = true;
    int n, m;
    cin >> n >> m;
    char s[10][20];
    for (int i = 0; i < m; i++)
        scanf("%s%s%s%s", &s[i][0], &s[i][3], &s[i][6], &s[i][8]);
    bool A[10];
    bool P[4];
    for (int t = 0; t < 16; t++)
    {
        for (int j = 0; j < 4; j++)
            P[j] = (t >> j) % 2;
        for (int i = 0; i < m; i++)
        {
            bool zuo = false, you = false;
            if (s[i][3] == 'A') zuo = A[s[i][4] - '0'];
            if (s[i][3] == 'P') zuo = P[s[i][4] - '0'];
            if (s[i][8] == 'A') you = A[s[i][9] - '0'];
            if (s[i][8] == 'P') you = P[s[i][9] - '0'];
            if (s[i][6] == '~') A[i] = !(zuo || you);
            if (s[i][6] == '>') A[i] = !zuo || you;
            if (s[i][6] == '^') A[i] = zuo && you;
            if (s[i][6] == 'v') A[i] = zuo || you;
        }
        if (A[m - 1] == false) chong = false;
        else mao = false;
    }
    if (chong) cout << 1;
    else if (mao) cout << -1;
    else cout << 0;
    return 0;
}
