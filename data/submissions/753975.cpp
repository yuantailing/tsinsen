#include <iostream>
#include <string>
using namespace std;

int main() {
    string dic[256];
    int dicSize = 0;
    string str;
    int pos = 0;
    cin >> str;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        dic[dicSize].clear();
        dic[dicSize].push_back(ch);
        dicSize++;
    }
    string s;
    int posSave = -1;
    while (1) {
        if (pos == str.length()) {
            cout << posSave << '-';
            break;
        }
        s.push_back(str[pos++]);
        int dicPos = -1;
        for (int j = 0; j < dicSize; j++) {
            if (dic[j] == s) {
                dicPos = j;
                break;
            }
        }
        if (dicPos >= 0) {
            posSave = dicPos;
            continue;
        }
        else {
            cout << posSave << '-';
            if (dicSize < 256)
                dic[dicSize++] = s;
            s.clear();
            pos--;
        }
    }
    return 0;
}
