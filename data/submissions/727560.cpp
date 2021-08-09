#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void deal(char *s, int lo, int hi) {
    if (hi - lo <= 1) return;
    char t = s[--hi];
    s[hi] = s[lo];
    s[lo] = t;
    cout << s;
    deal(s, ++lo, hi);
}

int main() {
    int n;
    char *s = new char[386 * 1024 * 1024];
    gets(s);
    sscanf(s, "%d", &n);
    while (*s == ' ') s++;
    while (*s != ' ') s++;
    while (*s == ' ') s++;
    deal(s, 0, n);
    cout << endl << s;
    return 0;
}
