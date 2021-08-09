#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int v[32769];

int main()
{
	for (int x1 = 0; x1 <= 181; x1++) {
		int a = x1 * x1;
		for (int x2 = x1; x2 <= 181; x2++) {
			int b = a + x2 * x2;
			if (b > 32768) break;
			for (int x3 = x2; x3 <= 181; x3++) {
				int c = b + x3 * x3;
				if (c > 32768) break;
				for (int x4 = x3; x4 <= 181; x4++) {
					int d = c + x4 * x4;
					if (d > 32768) break;
					v[d]++;
				}
			}
		}
	}
	int N;
	while (scanf("%d", &N) == 1)
		printf("%d\n", v[N]);	
	return 0;
}
