#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = 0;
    char d[1000];   //assert: 16^1000 should be sufficient!
    int i;
    for (i = 0; n > 0; i++)
    {
        a = n%16;
        n = n/16;
        if (a >= 10)
            d[i] = 'A'+a-10;
        else
            d[i] = '0'+a;
    }
    for (int j = i-1; j >= 0; j--)
        cout << d[j];
    return 0;
}
