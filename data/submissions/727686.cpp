#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int wv[21][21][21];
int noMeaning = -99998888;

int w(int a, int b, int c) {
    if (a<=0 || b<=0 || c<=0) return 1;
    if (a>20 || b>20 || c>20) {
        if (wv[20][20][20] == noMeaning)
            wv[20][20][20] = w(20,20,20);
        return wv[20][20][20];
    }
    if (a<b && b<c) {
        if (wv[a][b][c] == noMeaning)
            wv[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        return wv[a][b][c];
    }
    if (wv[a][b][c] == noMeaning)
        wv[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return wv[a][b][c];
}

int main() {
    int a, b, c;
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            for (int k = 0; k < 21; k++)
                wv[i][j][k] = noMeaning;
    while (1) {
        scanf("%d%d%d", &a, &b, &c);
        if (a==-1 && b==-1 && c==-1) break;
        printf("w(%d,%d,%d)=%d", a, b, c, w(a,b,c));
    }
    return 0;
}
