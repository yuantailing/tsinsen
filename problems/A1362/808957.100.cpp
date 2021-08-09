#include <iostream>
using namespace std;

bool p(int x) {
    if (x % 400 == 0) return true;
    if (x % 100 != 0 && x % 4 == 0) return true;
    return false;
}

int main() {
    int N, h;
    cin >> N >> h;
    for (int i = N; i < 2013; i++) {
        h += 365 + p(i);
    }
    cout << h << endl;
    return 0;
}
