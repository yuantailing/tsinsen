#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char ch;
    while (scanf("%c", &ch) != EOF && ch != '\n' && ch != '\r')
        printf("%c", ch+1);
    return 0;
}
