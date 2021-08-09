#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int cmp(void const *a, void const *b) {
    if (*(long long const *)a > *(long long const *)b) return 1;
    if (*(long long const *)a < *(long long const *)b) return -1;
    return 0;
}
int main() {
    int N;
    cin >> N;
    long long *a = new long long[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    qsort(a, N, sizeof(long long), cmp);
    long long *b = new long long[N];
    for (int i = 0; i < N; i++)
        b[i] = a[i] * a[i];
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        long long num, kind;
        cin >> num >> kind;
        if (kind == 0) {
            int lo = 0, hi = N;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (b[mid] <= num) lo = mid + 1;
                else hi = mid;
            }
            if (0 <= lo - 1 && lo - 1 < N)
                cout << a[lo - 1] << endl;
            else
                cout << -1 << endl;
        } else {
            int lo = 0, hi = N;
            while (lo < hi) {
                int mid = (lo + hi) >> 1;
                if (b[mid] < num) lo = mid + 1;
                else hi = mid;
            }
            if (0 <= hi && hi < N)
                cout << a[hi] << endl;
            else
                cout << -1 << endl;
        }
    }
    //system("pause");
    return 0;
}
