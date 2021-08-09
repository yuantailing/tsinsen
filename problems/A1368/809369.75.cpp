#include <iostream>
#include <cstdio>
#include <cstdlib>
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

/////
struct type2 {
    int no;
    type2 *pred;
    type2 *next;
} uh[100001];

int _cmp2(void const *pa, void const *pb) {
    if (H[((type2 *)pa)->no] > H[((type2 *)pb)->no]) return 1;
    return -1;
}

type2 *where[100001];

void updateCity() {
    for (int i = 0; i < N; i++) {
        uh[i].no = i + 1;
    }
    qsort(uh, N, sizeof(type2), &_cmp2);
    for (int i = 0; i < N; i++) {
        uh[i].pred = uh + i - 1;
        uh[i].next = uh + i + 1;
        where[uh[i].no] = uh + i;
    }
    uh[0].pred = uh[N - 1].next = 0;
    for (int i = 1; i < N - 1; i++) {
        type2 *t = where[i];
        type2 *compare1 = t->pred;
        type2 *compare2 = t->next;
        if (!compare1) {
            compare1 = compare2->next;
            city[t->no].next1 = compare2->no;
            city[t->no].next2 = compare1->no;
        } else if (!compare2) {
            compare2 = compare1->pred;
            city[t->no].next1 = compare1->no;
            city[t->no].next2 = compare2->no;
        } else {
            if (_cmp(compare1->no, compare2->no, t->no) == 1) {
                city[t->no].next1 = compare2->no;
                compare2 = compare2->next;
                if (!compare2) {
                    city[t->no].next2 = compare1->no;
                } else {
                    if (_cmp(compare1->no, compare2->no, t->no) == 1)
                        city[t->no].next2 = compare2->no;
                    else
                        city[t->no].next2 = compare1->no;
                }
            } else {
                city[t->no].next1 = compare1->no;
                compare1 = compare1->pred;
                if (!compare1) {
                    city[t->no].next2 = compare2->no;
                } else {
                    if (_cmp(compare1->no, compare2->no, t->no) == 1)
                        city[t->no].next2 = compare2->no;
                    else
                        city[t->no].next2 = compare1->no;
                }
            }
        }
        if (!t->next)
            t->pred->next = 0;
        else if (!t->pred)
            t->next->pred = 0;
        else {
            t->next->pred = t->pred;
            t->pred->next = t->next;
        }
    }
    city[N - 1].next1 = N;
    city[N - 1].next2 = -1;
    city[N].next1 = city[N].next2 = -1;
}
/////

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
    updateCity();
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
        if ((ans1.city == 0) ||
                (ans1.b == 0 && ret.b != 0) ||
                (ans1.b == 0 && ret.b == 0 && H[ans1.city] < H[i]) ||
                (ans1.b != 0 && ret.b != 0 && (long long)ans1.a*(long long)ret.b > (long long)ret.a*(long long)ans1.b) ||
                (ans1.b == 0 && ret.b == 0 && (long long)ans1.a*(long long)ret.b == (long long)ret.a*(long long)ans1.b && H[ans1.city] < H[i])) {
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
