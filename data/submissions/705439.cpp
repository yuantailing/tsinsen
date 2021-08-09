#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main() {
    int num;
    char s[256];
    int truth;
    cin >> num >> s >> truth;
    char name = *s;
    bool flag = false;
    for (int A = 1; A >= 0; A--)
    for (int B = 1; B >= 0; B--)
    for (int C = 1; C >= 0; C--)
    for (int D = 1; D >= 0; D--)
    for (int E = 1; E >= 0; E--)
    if (A + B + C + D + E == num) {
        bool pa, pb, pc, pd, pe;
        int X = name=='A'?A : name=='B'?B : name=='C'?C : name == 'D'?D : E;
        pa = (A ^ X) || (A && name == 'A');
        pb = C || E;
        pc = C || D || A;
        pd = !B && !C;
        pe = !E;
        if (pa + pb + pc + pd + pe == truth) {
            flag = true;
            if (A) cout << 'A';
            if (B) cout << 'B';
            if (C) cout << 'C';
            if (D) cout << 'D';
            if (E) cout << 'E';
            cout << endl;
        }
    }
    if (!flag)
        cout << 0;
    //system("pause");
    return 0;
}
