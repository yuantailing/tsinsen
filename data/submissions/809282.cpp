#include <iostream>
#include <vector>
using namespace std;

int n, s;
int len[301][301];
vector<int> vPath[301][301];
int W[301][301];

void updateLen(int a, int b, int source, int l) {
    if (a == b) return;
    if (source != 0 && len[a][b] == 0) {
        vPath[a][b] = vPath[a][source];
        vPath[a][b].push_back(source);
        vPath[b][a] = vPath[a][b];
    }
    len[a][b] = len[b][a] = l;
    for (int i = 1; i <= n; i++)
        if (W[b][i] && i != source)
            updateLen(a, i, b, l + W[b][i]);
}

int main() {
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        W[a][b] = W[b][a] = w;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (W[i][j])
                updateLen(i, j, 0, W[i][j]);
    /*for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cout << i << '\t' << j << '\t' << len[i][j] << '\t';
            cout << vPath[i][j].size() << ":";
            for (int k = 0; k < vPath[i][j].size(); k++)
                cout << vPath[i][j][k] << '|';
            cout << endl;
        }*/
    int core = 0x7fffffff;
    vector<int> from, to;
    int d = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (len[i][j] > d) {
                d = len[i][j];
                from.clear();
                to.clear();
            }
            if (len[i][j] == d) {
                from.push_back(i);
                to.push_back(j);
            }
        }
    for (int i = 0; i < from.size(); i++) {
        vector<int> P = vPath[from[i]][to[i]];
        P.push_back(from[i]);
        P.push_back(to[i]);
        for (int _i = 0; _i < P.size(); _i++)
            for (int _j = _i; _j < P.size(); _j++) {
                int i = P[_i], j = P[_j];
                if (len[i][j] <= s) {
                    int maxLen = 0;
                    for (int k = 1; k <= n; k++) {
                        int minLen = (len[k][i] + len[k][j] - len[i][j]) / 2;
                        if (minLen > maxLen) maxLen = minLen;
                    }
                    if (maxLen < core) core = maxLen;
                }
            }
    }
    cout << core << endl;
    return 0;
}
