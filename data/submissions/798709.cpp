/*************************************************************************
	> File Name: four.cpp
	> Created Time: Sun 29 Dec 2013 03:16:18 AM CST
	> Author: Wayne Ho
	> Mail: hewr2010@gmail.com 
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxBooks = 110000;

struct Book {
	int id; // book ID
	bool available; // true for borrowed

	Book():id(0), available(1) {}
	Book(int _id):id(_id), available(1) {}
};

struct System {
	Book books[MaxBooks]; // list of books
	int n; // number of books
} libr;

// YOU take care of interfaces below
void init();
bool borrowBook(int);
bool returnBook(int);

/*
 * BEGIN
 * enjoy yourself
 */
static int _cmp(void const *a, void const *b) {
	if (((Book *)a)->id > ((Book *)b)->id) return 1;
	else return -1;
}

void init() {
	qsort(libr.books, libr.n, sizeof(Book), &_cmp);
}

static int _search(int id) {
	int lo = 0, hi = libr.n;
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (libr.books[mi].id <= id)
			lo = mi + 1;
		else
			hi = mi;
	}
	if (libr.books[--lo].id == id)
		return lo;
	else
		return -1;
}

bool borrowBook(int id) {
	int pos = _search(id);
	if (pos == -1) return false;
	if (libr.books[pos].available == 0){
		return false;
	} else {
		libr.books[pos].available = 0;
		return true;
	}
}

bool returnBook(int id) {
	int pos = _search(id);
	if (pos == -1) return false;
	if (libr.books[pos].available == 0){
		libr.books[pos].available = 1;
		return true;
	} else {
		return false;
	}
}

/*
 * END
 */

int main(){
	int m;
	scanf("%d%d", &libr.n, &m);
	for (int i = 0; i < libr.n; ++i) scanf("%d", &libr.books[i].id);
	init();
	while (m--) {
		int kind, id;
		scanf("%d%d", &kind, &id);
		bool flag;
		if (!kind) flag = borrowBook(id);
		else flag = returnBook(id);
		printf("%d\n", flag);
	}

    return 0;
}
