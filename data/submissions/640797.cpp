#include <iostream>
#include <cstdio>
using namespace std;

int p, k, s;
char str[201];
char dict[6][201];
int len[6];
bool sc[200][6];

int nw[201][41];
int dp(int n, int k)//前n个字符分成k份。
{
    if (nw[n][k] >= 0)
        return nw[n][k];
    if (n < k) {
        nw[n][k] = 0;
        return 0;
    }
    int theMax = 0;
    for (int i = k - 1; i < n; i++) {//查找s[i~n]内单词数，存在ext内
        if (i < 0) continue;
        int ext = 0;
        for (int j = i; j < n; j++) {
            for (int q = 0; q < s; q++) {
                if (sc[j][q] && j + len[q] <= n) {
                    ext++;
                    break;
                }
            }
        }
        int t = ext + dp(i, k - 1);
        theMax = t > theMax ? t : theMax;
    }
    nw[n][k] = theMax;
    return theMax;
}

int main()
{
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 40; j++)
            nw[i][j] = -1;

    scanf("%d%d", &p, &k);
    for (int i = 0; i < p; i++)
        scanf("%s", str + 20 * i);
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        scanf("%s", dict[i]);
        int nLen = 0;
        while (dict[i][nLen]) nLen++;
        len[i] = nLen;
    }

    for (int i = 0; i < 20 * p; i++) {
        for (int j = 0; j < s; j++) {
            sc[i][j] = true;
            for (int k = 0; k < len[j]; k++) {
                if (i+k >= 20 * p || str[i+k] != dict[j][k])
                    sc[i][j] = false;
            }
        }
    }
    printf("%d", dp(20 * p, k));
    return 0;
}
