#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int *v = new int[N + 2];
    for (int i = 1; i <= N; i++)
        v[i] = 0;
    for (int i = 0; i < M; i++) {
        int L, R, C;
        scanf("%d%d%d", &L, &R, &C);
        v[L] += C;
        v[R + 1] -= C;
    }
    int sum = 0;
    for (int i = 1; i <= N; i++)
        printf("%d ", sum += v[i]);
    delete[] v;
    return 0;
}
