#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    string s("0");
    string t;
    unsigned n;
    cin >> n;
    for (unsigned i = 0; i < n; i++) {
        t.clear();
        for (unsigned j = 0; j < s.length(); j++) {
            if (s[j] == '0')
                t += "1";
            else
                t += "01";
        }
        s = t;
    }
    cout << s;
    return 0;
}
