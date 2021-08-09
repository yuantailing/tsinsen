#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

char s[2028];
int N;

void deal(int lo, int hi) {
    if (hi - lo > 1) {
        int mid = (lo + hi) >> 1;
        deal(lo, mid);
        deal(mid, hi);
    }
    bool B = true;
    bool I = true;
    while (lo < hi) {
        if (s[lo] != '0') B = false;
        if (s[lo] != '1') I = false;
        lo++;
    }
    if (B) cout << 'B';
    else if (I) cout << 'I';
    else cout << 'F';
}


int main() {
    gets(s);
    sscanf(s, "%d", &N);
    gets(s);
    deal(0, 1 << N);
    return 0;
}
