#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void count()
{
    int v[256];
    for (int i = 0; i < 256; i++)
        v[i] = 0;
    FILE *fp = fopen("input.txt", "r");
    char ch;
    while (fscanf(fp, "%c", &ch) == 1)
        v[ch]++;
    for (char i = 'A'; i <= 'Z'; i++) {
        int sum = v[i] + v[i - 'A' + 'a'];
        if (sum)
            printf("%c %d\n", i, sum);
    }
    fclose(fp);
}
