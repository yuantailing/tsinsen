#include <iostream>
using namespace std;

int a[10000], b[10000], g[10000], k[10000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> g[i] >> k[i];
    }
    int x, y;
    cin >> x >> y;
    int top = -1;
    for (int i = 0; i < n; i++) {
        if (x >= a[i] && x < a[i] + g[i] && y >= b[i] && y < b[i] + k[i])
            top = i + 1;
    }
    cout << top << endl;
    return 0;
}
