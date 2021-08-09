#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x > 1000)
            sum += x - 1000;
    }
    cout << sum << endl;
    return 0;
}
