#include <iostream>
#include <cstdio>

using namespace std;

bool isCh(char c) {
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

int main()
{
    char s[1<<8];
    gets(s);
    int len = 0;
    while (s[len]) len++;
    bool inWord = false;
    int start;
    for (int i = 0; i <= len; i++) {
        if (isCh(s[i])) {
            if (!inWord) {
                inWord = true;
                start = i;
            } else
                continue;
        } else {
            if (!inWord)
                continue;
            else {
                inWord = false;
                for (int j = start; j <= (i+start)/2; j++) {
                    char t = s[j];
                    s[j] = s[i+start-j-1];
                    s[i+start-j-1] = t;
                }
            }
        }
    }
    cout << s;
    return 0;
}
