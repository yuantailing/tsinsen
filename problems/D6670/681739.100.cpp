#include <iostream>
#include <cstdio>
using namespace std;

struct polynode{
    int coef; /*每一项的系数*/
    int exp; /*每一项的指数*/
    struct polynode *next; /*指向下一项的指针*/
};

void sort(polynode *head) {
    polynode *p = head->next;
    while (p) {
        polynode *q = p->next;
        while (q) {
            if (p->exp < q->exp) {
                int c = p->coef;
                int e = p->exp;
                p->coef = q->coef;
                p->exp = q->exp;
                q->coef = c;
                q->exp = e;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void print(int coef, int exp) {
    static bool isFirstOutput = true;
    if (coef == 0)
        return;
    if (coef > 0) {
        if (isFirstOutput) {
            isFirstOutput = false;
            if (coef != 1)
                printf("%d", coef);
        } else {
            printf("+");
            if (coef != 1)
                printf("%d", coef);
        }
    } else {
        if (isFirstOutput)
            isFirstOutput = false;
        if (coef == -1) {
            printf("-");
            if (exp == 0)
                printf("1");
        } else
            printf("%d", coef);

    }
    if (exp >= 2)
        printf("X^%d", exp);
    else if (exp == 1)
        printf("X");
}

void simp(polynode *p) {
    while (p && p->next && p->exp == p->next->exp) {
        p->coef = p->coef + p->next->coef;
        polynode *q = p->next;
        p->next = p->next->next;
        delete q;
    }
}

int main()
{
    int M, N;
    cin >> M >> N;
    polynode *p1 = new polynode;
    polynode *t = p1;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        polynode *q = new polynode;
        q->coef = a;
        q->exp = b;
        q->next = 0;
        t->next = q;
        t = q;
    }
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        polynode *q = new polynode;
        q->coef = a;
        q->exp = b;
        q->next = 0;
        t->next = q;
        t = q;
    }
    sort(p1);
    t = p1->next;
    while (t) {
        simp(t);
        print(t->coef, t->exp);
        t = t->next;
    }
    polynode *q = p1->next;
    while (q) {
        delete p1;
        p1 = q;
        q = q->next;
    }
    delete p1;
    return 0;
}
