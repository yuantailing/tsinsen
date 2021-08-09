#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    int a[100][100];
    for (int i = 0; i < x.length(); i++)
        for (int j = 0; j < y.length(); j++) {
            if (i == 0 && j == 0)
                a[i][j] = (x[i] == y[j]);
            else if (i == 0)
                a[i][j] = a[i][j-1] | (x[i] == y[j]);
            else if (j == 0)
                a[i][j] = a[i-1][j] | (x[i] == y[j]);
            else
                a[i][j] = max(max(a[i][j-1], a[i-1][j]), a[i-1][j-1] + (x[i] == y[j]));
        }
    cout << a[x.length()-1][y.length()-1];
    return 0;
}
