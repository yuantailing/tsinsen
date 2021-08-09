#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "WYS") cout << "KXZSMR" << endl;
        else if (s == "CQ") cout << "CHAIQIANG" << endl;
        else if (s == "LC") cout << "DRAGONNET" << endl;
        else if (s == "SYT") cout << "STUDYFATHER" << endl;
        else if (s == "SSD") cout << "STUDYFATHER" << endl;
        else if (s == "LSS") cout << "STUDYFATHER" << endl;
        else if (s == "LYF") cout << "STUDYFATHER" << endl;
        else cout << "DENOMINATOR" << endl;
    }
    return 0;
}
