#include <iostream>
#include <cstdio>
using namespace std;

char s[8001];
int len = 0;
int ans = 0;
int countS[26];

void move(int from, int to) {
    if (from < to) {
        int t = s[from];
        for (int i = from; i < to; i++)
            s[i] = s[i + 1];
        s[to] = t;
        ans += to - from;
    } else if (from > to){
        int t = s[from];
        for (int i = from; i > to; i--)
            s[i] = s[i - 1];
        s[to] = t;
        ans += from - to;
    }
}

int main() {
    scanf("%d", &len);
    while (!*s) gets(s);
    for (int i = 0; i < len; i++)
        countS[s[i] - 'a']++;
    char single = 0;
    for (int i = 0; i < 26; i++) {
        if (countS[i] % 2) {
            if (single) {
                printf("Impossible\n");
                return 0;
            } else
                single = i + 'a';
        }
    }
    int mid = len >> 1;
    for (int i = 0; i < mid; i++) {
        if (countS[s[i] - 'a'] == 1) {
            move(i, i+1);
            i--;
            continue;
        }
        int mirror = len - i - 1;
        int j;
        for (j = mirror; s[i] != s[j]; j--);
        move(j, mirror);
        countS[s[i] - 'a'] -= 2;
    }
    cout << ans << endl;
    return 0;
}
