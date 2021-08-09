#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool isNum(char c) {
    return c >= '0' && c <= '9';
}

bool isAlpha(char c) {
    return c >= 'a' && c <= 'z';
}

bool isPair(char a, char b) {
    return ((isNum(a) && isNum(b)) || (isAlpha(a) && isAlpha(b))) && a < b;
}

int main() {
    int p1, p2, p3;
    char s[128] = "";
    cin >> p1 >> p2 >> p3;
    while (strlen(s) == 0) gets(s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '-') {
            if (i > 0 && isPair(s[i - 1], s[i + 1])) {
                if (p3 == 1) {
                    for (char c = s[i - 1] + 1; c < s[i + 1]; c++) {
                        char o = c;
                        if (p1 == 2) o = c - 'a' + 'A';
                        else if (p1 == 3) o = '*';
                        for (int j = 0; j < p2; j++)
                            cout << o;
                    }
                } else {
                    for (char c = s[i + 1] - 1; c > s[i - 1]; c--) {
                        char o = c;
                        if (p1 == 2) o = c - 'a' + 'A';
                        else if (p1 == 3) o = '*';
                        for (int j = 0; j < p2; j++)
                            cout << o;
                    }
                }
            } else
                cout << '-';
        } else {
            cout << s[i];
        }
    }
    return 0;
}
