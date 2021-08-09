#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


string dic[256];
int dicSize = 0;
void showDic() {
    cout << "Dic: ";
    for (int i = 26; i < dicSize; i++)
        cout << '[' << i << ']' << dic[i] << ' ';
    cout << endl;
}

int main() {
    string str;
    int pos = 0;
    cin >> str;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        dic[dicSize].clear();
        dic[dicSize].push_back(ch);
        dicSize++;
    }
    string s;
    char x;

    int posSave = -1;
    while (1) {
        if (pos == str.length()) {
            cout << posSave << '-';
            break;
        }
        x = str[pos++];
        s.push_back(x);
        int dicPos = -1;
        for (int j = 0; j < dicSize; j++) {
            if (dic[j] == s)
                dicPos = j;
        }
        if (dicPos >= 0) {
            posSave = dicPos;
            continue;
        }
        else {
            cout << posSave << '-';
            dic[dicSize++] = s;
            if (s.length() <= 1) exit(-1);
            s.clear();
            pos--;
        }
    }
    return 0;
}
