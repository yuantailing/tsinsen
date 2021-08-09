#include <iostream>
using namespace std;

int N, M;
int a[1024][1024];
bool b[1024][1024];
int count = 0;

void expand(int x, int y) {
    b[x][y] = true;
    if (x-1 >= 0 && !b[x-1][y] && a[x-1][y] < a[x][y]) expand(x-1, y);
    if (x+1 <  N && !b[x+1][y] && a[x+1][y] < a[x][y]) expand(x+1, y);
    if (y-1 >= 0 && !b[x][y-1] && a[x][y-1] < a[x][y]) expand(x, y-1);
    if (y+1 <  M && !b[x][y+1] && a[x][y+1] < a[x][y]) expand(x, y+1);
}

int check() {
    int c = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!b[i][j]) c++;
    return c;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
            b[i][j] = false;
        }
    while (1) {
        int max = -1;
        for (int i = 0; i < M; i++)
            if (!b[0][i] && a[0][i] > max) max = a[0][i];
        if (max == -1) break;
        for (int i = 0; i < M; i++)
            if (!b[0][i] && a[0][i] == max) {
                count++;
                expand(0, i);
            }
    }
    int remain = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (!b[i][j]) remain++;
    if (remain == 0) cout << 1 << endl << count << endl;
    else cout << 0 << endl << remain << endl;
    return 0;
}
