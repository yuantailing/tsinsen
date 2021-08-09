#include <iostream>
using namespace std;

int main()
{
    int z[4000], ztop = 0;
    z[ztop++] = 2;
    for (int x = 3; x < 35000; x += 2) {
        bool flag = true;
        for (int j = 3; j * j < x; j++)
            if (!(x%j)) {
                flag = false;
                break;
            }
        if (flag)
            z[ztop++] = x;
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int ans = 1;
        int zn = 0;
        int p = z[zn];
        int np = 0;
        while (x > 1) {
            if (x%p==0) {
                x/=p;
                np++;
            } else {
                if (np) {
                    ans *= (np + 1);
                    np = 0;
                }
                p = z[++zn];
                if (p * p > x) {
                    np++;
                    break;
                }
            }
        }
        ans *= (np + 1);
        cout << ans << endl;
    }
    return 0;
}
