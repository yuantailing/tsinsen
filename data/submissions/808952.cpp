#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int *X = new int[N];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        sum += X[i];
    }
    sum /= N;
    int delta = 0;
    int price = 0;
    for (int i = 0; i < N; i++) {
        delta = delta + X[i] - sum;
        price += delta < 0 ? -delta : delta;
    }
    cout << price << endl;
    delete[] X;
    return 0;
}
