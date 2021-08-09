#include <cstdio>
using namespace std;

int main() {
    char k[101];
    scanf("%s", k);
    int v[128];
    for (int i = 0; k[i]; i++)
        v[i] = k[i] >= 'a' ? k[i] - 'a' : k[i] - 'A';
    int p = 0;
    char ch = 0;
    while (ch != '\n') scanf("%c", &ch);
    while (scanf("%c", &ch) == 1 && ch != '\r' && ch != '\n') {
        int a = ch >= 'a' ? ch - 'a' : ch - 'A';
        int b = a - v[p];
        if (b < 0) b += 26;
        putchar(ch >= 'a' ? 'a' + b : 'A' + b);
        p++;
        if (!k[p]) p = 0;
    }
    putchar('\n');
    return 0;
}
