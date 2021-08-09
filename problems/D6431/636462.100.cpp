#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    char man;
    for (man = 'A'; man <= 'E'; man++) {
        bool a, b, c, d, e;
        a = man != 'A' && man != 'E';
        b = man == 'C' || man == 'E';
        c = man == 'C' || man == 'D';
        d = man != 'B' && man != 'C';
        e = man != 'E';
        if (a + b + c + d + e == 2)
            cout << man << ' ';
    }
    return 0;
}
