#include <iostream>
#include <cstdio>
using namespace std;

int t[500], len[75];
int main() {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (t[i] > t[j]) {
                int x = t[i];
                t[i] = t[j];
                t[j] = x;
            }
    int u = 0;
    for (int i = 0; i < n; i++) {
        int mp = 0;
        for (int j = 1; j < r; j++)
            if (len[j] < len[mp])
                mp = j;
        u += len[mp] += t[i];
    }
    cout << u;
    return 0;
}
