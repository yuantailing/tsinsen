#include <iostream>
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
    while (!*s) cin >> s;
    int len = 0;
    while (s[len]) len++;
    for (int i = 0; i < len; i++)
        if (s[i] == '-' && i > 0 && isPair(s[i - 1], s[i + 1]))
            if (p3 == 1)
                for (char c = s[i - 1] + 1; c < s[i + 1]; c++) {
                    char o = p1 == 3 ? '*' : p1 == 1 || isNum(c) ? c : c - 'a' + 'A';
                    for (int j = 0; j < p2; j++)
                        cout << o;
                }
            else
                for (char c = s[i + 1] - 1; c > s[i - 1]; c--) {
                    char o = p1 == 3 ? '*' : p1 == 1 || isNum(c) ? c : c - 'a' + 'A';
                    for (int j = 0; j < p2; j++)
                        cout << o;
                }
        else
            cout << s[i];
    return 0;
}
