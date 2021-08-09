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

void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            b[i][j] = false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    for (int i = 0; i < M; i++) {
        if (!b[0][i]) expand(0, i);
    }
    int remain = 0;
    for (int i = 0; i < M; i++)
        if (!b[N - 1][i]) remain++;
    if (remain > 0) {
        cout << 0 << endl << remain << endl;
        return 0;
    }
    while (1);
    return 0;
}
