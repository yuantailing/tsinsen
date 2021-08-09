#include <iostream>

using namespace std;

int N, M;
int a[360];
int card[5];
int ****s;

int solve(int pos, int card4, int card3, int card2) {
    if (pos == 1) return a[1];
    if (pos < 1 || card4 < 0 || card3 < 0 || card2 < 0) return -1;
    int card1 = pos - 1 - 4 * card4 - 3 * card3 - 2 * card2;
    if (card1 < 0) return -1;
    if (s[pos][card4][card3][card2] != -1)
        return s[pos][card4][card3][card2];
    if (pos == 1) return s[pos][card4][card3][card2] = a[1];
    int t1 = solve(pos - 1, card4, card3, card2) + a[pos];
    int t2 = solve(pos - 2, card4, card3, card2 - 1) + a[pos];
    int t3 = solve(pos - 3, card4, card3 - 1, card2) + a[pos];
    int t4 = solve(pos - 4, card4 - 1, card3, card2) + a[pos];
    int max = t1;
    if (t2 > max) max = t2;
    if (t3 > max) max = t3;
    if (t4 > max) max = t4;
    return s[pos][card4][card3][card2] = max;
}

int main()
{
    cin >> N >> M;
    s = new int ***[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        card[c]++;
    }
    for (int i = 1; i <= N; i++) {
        s[i] = new int **[card[4] + 1];
        for (int j = 0; j <= card[4]; j++) {
            s[i][j] = new int *[card[3] + 1];
            for (int k = 0; k <= card[3]; k++) {
                s[i][j][k] = new int[card[2] + 1];
                for (int l = 0; l <= card[2]; l++)
                    s[i][j][k][l] = -1;
            }
        }
    }
    cout << solve(N, card[4], card[3], card[2]);
    return 0;
}
