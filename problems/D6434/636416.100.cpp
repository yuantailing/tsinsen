#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char *s = new char[100001];
    scanf("%s", s);
    int start, step;
    scanf("%d%d", &start, &step);
    int len = 0;
    while (s[len]) len++;
    for (int i = start; i < len; i += step)
        printf("%c", s[i]);
    delete[] s;
    return 0;
}
