#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

const int MaxLength = 110000;
char arrS[MaxLength];

string strS;

void solve()
{
	FILE *fin = fopen("file.in", "r");
	FILE *fout = fopen("file.out", "w");
	char ch;
	while (fscanf(fin, "%c", &ch) == 1 && ch >= 'a' && ch <= 'z') {
		if (ch == 'z')
			fprintf(fout, "%c", 'a');
		else
			fprintf(fout, "%c", ch + 1);
	}
	fclose(fin);
	fclose(fout);
}
