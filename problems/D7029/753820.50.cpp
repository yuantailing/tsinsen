#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    cout << (N - N % 4) / 2;
    return 0;
}
