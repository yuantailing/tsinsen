#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool isprime(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    int sqrtx = sqrt(x) + 1;
    for (int i = 3; i <= sqrtx; i+=2)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> v;
    for (int i = 1; i < 10; i++)
        if (isprime(i))
            v.push_back(i);
    for (int i = 1; i < N; i++) {
        vector<int> a;
        a.clear();
        int size = v.size();
        for (int k = 0; k < size; k++)
            for (int j = 1; j < 10; j++)
                if (isprime(v[k]*10+j))
                    a.push_back(v[k]*10+j);
        v = a;
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
