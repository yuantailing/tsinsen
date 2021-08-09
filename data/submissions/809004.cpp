#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *v = new int[n];
    for (int i = 0; i < n; cin >> v[i++]);
    sort(v, v + n);
    int num = v[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] == num) count++;
        else {
            cout << num << ' ' << count << endl;
            num = v[i];
            count = 1;
        }
    }
    cout << num << ' ' << count << endl;
    return 0;
}
