#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    bool num[10][7] = {
        {1,1,1,1,1,1,0},
        {0,1,1,0,0,0,0},
        {1,1,0,1,1,0,1},
        {1,1,1,1,0,0,1},
        {0,1,1,0,0,1,1},
        {1,0,1,1,0,1,1},
        {1,0,1,1,1,1,1},
        {1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1},
        {1,1,1,1,0,1,1}
    };
    char buffer[256];
    gets(buffer);
    int L;
    sscanf(buffer, "%d", &L);
    char x[256];
    char y[256];
    gets(x);
    gets(y);
    int sum = 0;
    for (int i = 0; i < L; i++) {
        x[i] -= '0';
        y[i] -= '0';
        for (int j = 0; j < 7; j++)
            if (num[x[i]][j] != num[y[i]][j])
                sum++;
    }
    printf("%d", sum);
    return 0;
}
