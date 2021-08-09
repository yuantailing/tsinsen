#include <iostream>
using namespace std;

int main()
{
    int N, a[10000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        int ans = 1;
        int p = 2;
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
                p++;
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
