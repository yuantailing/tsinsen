#include <iostream>
#include <cstdio>

using namespace std;

bool isCh(char c) {
    return (c>='A' && c<='Z') || (c>='a' && c<='z');
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int *v = new int[1<<20];
    for (int i = 0; i < N; i++)
        scanf("%d", v+i);
    int e;
    while (scanf("%d", &e) == 1) {
        int lo = 0, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (e < v[mi])
                hi = mi;
            else
                lo = mi + 1;
        }
        --lo;
        printf("%d\n", v[lo]==e ? lo : -1);
    }
    return 0;
}
