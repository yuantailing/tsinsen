#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void revcp(char *inp, char *oup)
{
FILE *fpi = fopen(inp, "r");
FILE *fpo = fopen(oup, "w");
char s[10001];
char ss[10001];
fscanf(fpi, "%s", s);
int len = 0;
while (s[len]) len++;
for (int i = 0; i < len; i++)
ss[i] = s[len-i-1];
ss[len] = 0;
fprintf(fpo, "%s", ss);
fclose(fpi);
fclose(fpo);
}
