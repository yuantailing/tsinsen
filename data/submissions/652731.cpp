#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

void printStr(char *st)
{
FILE *fp = fopen("output.txt", "w");
fprintf(fp, "%s", st);
fclose(fp);
}
