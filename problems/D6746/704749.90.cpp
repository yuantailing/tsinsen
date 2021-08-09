#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

void deal(int &a1, int &a2, char *s) {
	if (*s == '*') {
		a1 = 0;
		a2 = 255;
	} else {
		int i = 0;
		while (s[i]) {
			if (s[i] == '-') break;
			i++;
		}
		if (s[i]) {
			a1 = 0;
			for (int j = 0; j < i; j++) {
				a1 *= 10;
				a1 += s[j] - '0';
			}
			a2 = 0;
			for (int j = i + 1; s[j]; j++) {
				a2 *= 10;
				a2 += s[j] - '0';
			}
		} else {
			a1 = 0;
			for (int j = 0; s[j]; j++) {
				a1 *= 10;
				a1 += s[j];
			}
			a2 = a1;
		}
	}
	if (a1 > a2) {
		int t = a1;
		a1 = a2;
		a2 = a1;
	}
}

int main() {
	char str[256];
	gets(str);
	int a1[4], a2[4];
	int pos = 0;
	int former = -1;
	int tmp = 0;
	while (tmp < 4) {
		if (str[pos] == '.' || str[pos] == 0) {
			str[pos] = 0;
			deal(a1[tmp], a2[tmp], str + former + 1);
			tmp++;
			former = pos;
		}
		pos++;
	}
	char buffer[256];
	gets(buffer);
	int n;
	sscanf(buffer, "%d", &n);
	for (int i = 0; i < n; i++) {
		gets(buffer);
		int a[4];
		sscanf(buffer, "%d.%d.%d.%d", a, a + 1, a + 2, a + 3);
		bool ok = true;
		for (int i = 0; i < 4; i++)
			if (!(a1[i] <= a[i] && a[i] <= a2[i]))
				ok = false;
		if (ok)
			cout << "Accepted" << endl;
		else
			cout << "Failed" << endl;
	}
	//system("pause");
	return 0;
}
