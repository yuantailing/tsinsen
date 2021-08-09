#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int H[100001];
int X0;

struct node {
    int x;
    int y;
    int next1;
    int next2;
} city[100001];

struct retType {
    int a;
    int b;
};

int d(int a, int b) {
    if (H[a] > H[b]) return H[a] - H[b];
    return H[b] - H[a];
}

int _cmp(int a, int b, int from) {
    int da = d(a, from);
    int db = d(b, from);
    if (da > db) return 1;
    if (da == db && H[a] > H[b]) return 1;
    return -1;
}

void updateN12(int S) {
    int n1 = -1;
    int n2 = -1;
    for (int i = S + 1; i <= N; i++) {
        if (n1 == -1 || _cmp(n1, i, S) == 1) {
            n2 = n1;
            n1 = i;
        } else if (n2 == -1 || _cmp(n2, i, S) == 1)
            n2 = i;
    }
    city[S].next1 = n1;
    city[S].next2 = n2;
}

retType solve(int S, int X) {
    retType ret;
    ret.a = ret.b = 0;
    bool driverA = true;
    while (1) {
        if (driverA) {
            if (city[S].next2 == 0)
                updateN12(S);
            if (city[S].next2 == -1)
                break;
            int dis = d(S, city[S].next2);
            if (X < dis) break;
            ret.a += dis;
            X -= dis;
            S = city[S].next2;
            driverA = false;
        } else {
            if (city[S].next1 == 0)
                updateN12(S);
            if (city[S].next1 == -1)
                break;
            int dis = d(S, city[S].next1);
            if (X < dis) break;
            ret.b += dis;
            X -= dis;
            S = city[S].next1;
            driverA = true;
        }
    }
    return ret;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", H + i);
        city[i].x = i;
        city[i].y = H[i];
        city[i].next1 = 0;
        city[i].next2 = 0;
    }
    scanf("%d", &X0);
    struct {
        int a;
        int b;
        int city;
    } ans1;
    ans1.city = 0;
    for (int i = 1; i <= N; i++) {
        retType ret = solve(i, X0);
        //printf("from:%d\ta:%d\tb:%d\n", i, ret.a, ret.b);
        if (ans1.city == 0 ||
                (ans1.b == 0 && ret.b != 0) || (
                !(ans1.b != 0 && ret.b == 0) && (
                    (ans1.a * ret.b > ret.a * ans1.b) ||
                    (ans1.a * ret.b == ret.a * ans1.b && H[ans1.city] < H[i])
                    ))) {
            ans1.a = ret.a;
            ans1.b = ret.b;
            ans1.city = i;
        }
    }
    printf("%d\n", ans1.city);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int S, X;
        scanf("%d%d", &S, &X);
        retType ret = solve(S, X);
        printf("%d %d\n", ret.a, ret.b);
    }
    return 0;
}
