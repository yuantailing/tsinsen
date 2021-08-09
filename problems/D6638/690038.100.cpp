#include <cstdio>
using namespace std;

int search(int a[], int b, int start, int end) {
    while (start <= end)
    {
        int middle = (end+start)/2;
        if (a[middle] == b) return middle;
        if (a[middle] < b) start = middle + 1;
        else end = middle - 1;
    }
    return -1;
}

int main() {
    const int MAX = 1000000;
    int *a = new int[MAX], b;
    int N, M;
    scanf("%d %d", &N, &M); //same as cin >> N >> M
    //assert: N <= MAX
    for (int i = 0; i < N; i++)
        scanf("%d", &a[i]); //same as cin >> a[i], but faster!
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &b); //same as cin >> b, but faster!
        printf("%d\n", search(a, b, 0, N-1));   //same as cout << search(a, b, 0, N-1) << endl, but faster!
    }
    delete[] a;
    return 0;
}
