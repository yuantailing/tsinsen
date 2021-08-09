#include <iostream>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    int *c = new int[n], *d = new int[n];
    int *nColor = new int[k];
    for (int i = 0; i < k; i++)
        nColor[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> d[i];
        nColor[c[i]]++;
    }
    int count = 0;
    for (int color = 0; color < k; color++) {
        bool cheap = false;
        int nFirst = 0;
        int choise = nColor[color];
        for (int i = 0; i < n; i++) {
            if (d[i] <= p) cheap = true;
            if (cheap && nFirst > 0) {
                count += nFirst * choise;
                nFirst = 0;
                cheap = (d[i] <= p);
            }
            if (c[i] == color) {
                nFirst++;
                cheap = (d[i] <= p);
                choise--;
            }
            if (cheap && nFirst > 0) {
                count += nFirst * choise;
                nFirst = 0;
                cheap = (d[i] <= p);
            }
        }
    }
    cout << count << endl;
    return 0;
}
