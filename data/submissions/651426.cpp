#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int *v = new int[N + 1];
    for (int i = 1; i <= N; i++)
        v[i] = 0;
    for (int i = 0; i < M; i++) {
        int L, R, C;
        cin >> L >> R >> C;
        for (int j = L; j <= R; j++)
            v[j] += C;
    }
    for (int i = 1; i <= N; i++)
        cout << v[i] << ' ';
    delete[] v;
    return 0;
}
