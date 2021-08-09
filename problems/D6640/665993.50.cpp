#include <iostream>
using namespace std;

int main()
{
    int s, t, a, b, c, d;
    cin >> s >> t >> a >> b >> c >> d;
    int m[4];
    int m1[4] = {1,1,1,1}, m2[4] = {1,1,1,1};
    int q[4];
    q[0] = a;
    q[1] = b;
    q[2] = c;
    q[3] = d;
    if (a>1 && b>1 && c>1 && d>1) {
        for (int i = 1; i <= 2; i++)
            if (s <= i && i <= t)
                cout << i << ' ';
    }
    int n = 3;
    while (n <= s) {
        for (int j = 0; j < 4; j++) {
            m[j] = m1[j] + m2[j];
            while (m[j] >= q[j])
                m[j] -= q[j];
            m2[j] = m1[j];
            m1[j] = m[j];
        }
        n++;
    }
    while (n <= t) {
        bool flag = true;
        for (int j = 0; j < 4; j++) {
            m[j] = m1[j] + m2[j];
            while (m[j] >= q[j])
                m[j] -= q[j];
            m2[j] = m1[j];
            m1[j] = m[j];
            if (!m[j])
                flag = false;
        }
        if (flag)
            cout << n << ' ';
        n++;
    }
    return 0;
}
