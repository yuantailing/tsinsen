#include <iostream>
#include <cstdio>
using namespace std;

struct polynode{
    int coef; /*每一项的系数*/
    int exp; /*每一项的指数*/
    struct polynode *next; /*指向下一项的指针*/
};

void sort(polynode *head) {
    polynode *p = head;
    while (p->next) {
        p = p->next;
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
    }
}

void print(int coef, int exp) {
    /*cout << coef << " " << exp << endl;*/
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
        p->coef == p->coef + p->next->coef;
        p->next = p->next->next;
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
    polynode *p2 = new polynode;
    t = p2;
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
    sort(p2);
    polynode *t1 = p1->next;
    polynode *t2 = p2->next;
    for (int i = 0; i < N; i++) {
        int a = t2->coef;
        int b = t2->exp;
        t2 = t2->next;
        simp(t2);
        while (t1 && t1->exp > b) {
            print(t1->coef, t1->exp);
            t1 = t1->next;
            simp(t1);
        }
        if (t1 && t1->exp == b) {
            print(t1->coef + a, t1->exp);
            t1 = t1->next;
            simp(t1);
        } else {
            print(a, b);
        }
    }
    if (t1)
        print(t1->coef, t1->exp);
    return 0;
}
