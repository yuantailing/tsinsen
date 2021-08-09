#include <iostream>
using namespace std;

int s[100][100];
int h[100][100];
int N, M;

void expand(int x, int y, int highest) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (highest >= h[x][y]) return;
    if (highest < s[x][y]) highest = s[x][y];
    h[x][y] = highest;
    expand(x-1, y, highest);
    expand(x+1, y, highest);
    expand(x, y-1, highest);
    expand(x, y+1, highest);
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> s[i][j];
            h[i][j] = 1e8;
        }
    for (int i = 0; i < N; i++) {
        expand(i, 0, s[i][0]);
        expand(i, M-1, s[i][M-1]);
    }
    for (int j = 1; j < M - 1; j++) {
        expand(0, j, s[0][j]);
        expand(N-1, j, s[N-1][j]);
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (h[i][j] > s[i][j])
                sum += h[i][j] - s[i][j];
    }
    cout << sum << endl;
    return 0;

}
