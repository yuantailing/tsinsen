#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int lin = 0, li = 0;
    while (lin < 21 && li < 21 || lin - li <= 1 && li - lin <= 1) {
        int code;
        cin >> code;
        code ? li++ : lin++;
    }
    if (li < 21)
        cout << 0;
    else
        cout << 1;
    return 0;
}
