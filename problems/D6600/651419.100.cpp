#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a[100], sum = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x * a[i];
    }
    cout << sum;
    return 0;
}
