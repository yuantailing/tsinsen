#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    int i = 2;
    while (N % i) i++;
    cout << (N - i) / 2;
    return 0;
}
