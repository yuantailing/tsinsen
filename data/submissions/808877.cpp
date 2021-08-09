#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class game {
public:
    game() { memset(this, 0, sizeof(*this)); }
    void print() const { for (int i = 0; i < 7; i++) { for (int j = 0; j < 5; j++) cout << (int)pic[6-i][j] << ' '; cout << endl; } }
    void showStep() const { for (int i = 0; i < nStep; i++) cout << (int)step[i].x << ' ' << (int)step[i].y << ' ' << (int)step[i].direct << endl; }
    void move(char x, char y, char direct) {
        if ((x == 0 && direct == -1) || (x == 4 && direct == 1)) throw int(1);
        if (pic[y][x] == 0) throw int(2);
        int x2 = x + direct;
        char t = pic[y][x2];
        pic[y][x2] = pic[y][x];
        pic[y][x] = t;
        drop();
        while (1) {
            if (bomb()) drop();
            else break;
        }
        step[nStep].x = x;
        step[nStep].y = y;
        step[nStep].direct = direct;
        nStep++;
    }
    bool drop() {
        bool ret = false;
        for (int x = 0; x < 5; x++) {
            int y1 = 0;
            for (int y2 = 0; y2 < 7; y2++) {
                if (pic[y2][x] != 0) {
                    pic[y1][x] = pic[y2][x];
                    if (y1 != y2) {
                        ret = true;
                        pic[y2][x] = 0;
                    }
                    y1++;
                }
            }
        }
        return ret;
    }
    bool bomb() {
        bool toClear[7][5];
        memset(toClear, 0, sizeof(toClear));
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 7; y++)
                if (pic[x][y] == 0) continue;
                else {
                    int nx = 1, ny = 1;
                    int tx = x + 1;
                    while (tx < 5 && pic[tx][y] == pic[x][y]) {
                        nx++;
                        tx++;
                    }
                    tx = x - 1;
                    while (tx >= 0 && pic[tx][y] == pic[x][y]) {
                        nx++;
                        tx--;
                    }
                    if (nx >= 3) {
                        tx = x + 1;
                        while (tx < 5 && pic[tx][y] == pic[x][y]) {
                            toClear[tx][y] = true;
                            tx++;
                        }
                        tx = x - 1;
                        while (tx >= 0 && pic[tx][y] == pic[x][y]) {
                            toClear[tx][y] = true;
                            tx--;
                        }
                    }
                    int ty = y + 1;
                    while (ty < 7 && pic[x][ty] == pic[x][y]) {
                        ny++;
                        ty++;
                    }
                    ty = y - 1;
                    while (ty >= 0 && pic[x][ty] == pic[x][y]) {
                        ny++;
                        ty--;
                    }
                    if (ny >= 3) {
                        ty = y + 1;
                        while (ty < 7 && pic[x][ty] == pic[x][y]) {
                            toClear[x][ty] = true;
                            ty++;
                        }
                        ty = y - 1;
                        while (ty >= 0 && pic[x][ty] == pic[x][y]) {
                            toClear[x][ty] = true;
                            ty--;
                        }
                    }
                }
        bool ret = false;
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 7; y++) {
                if (toClear[x][y]) {
                    ret = true;
                    pic[x][y] = 0;
                }
            }
        return ret;
    }
    bool checkClear() const {
        for (int x = 0; x < 5; x++)
            if (pic[0][x]) return false;
        return true;
    }
    bool checkPossibility() const {
        int vColor[11];
        memset(vColor, 0, sizeof(vColor));
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 7; y++)
                vColor[pic[y][x]]++;
        for (int i = 1; i <= 10; i++)
            if (vColor[i] > 0 && vColor[i] < 3)
                return false;
        return true;
    }

public:
    char pic[7][5];
    char nStep;
    struct {
        char x, y, direct;
    } step[5];
};

int n;

void dfs(game const &g) {
    if (g.nStep == n) {
        if (g.checkClear()) {
            g.showStep();
            exit(0);
        } else
            return;
    }
    if (!g.checkPossibility()) return;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 7; y++)
            for (int direct = 1; direct >= -1; direct -= 2) {
                if (x+direct < 0 || x+direct >= 5 || g.pic[y][x] == 0)
                    continue;
                game newGame = g;
                newGame.move(x, y, direct);
                dfs(newGame);
            }
}

int main() {
    cin >> n;
    game G;
    for (int i = 0; i < 5; i++) {
        int j = 0;
        while (1) {
            int buf;
            cin >> buf;
            if (buf == 0) break;
            else G.pic[j++][i] = buf;
        }
    }
    dfs(G);
    cout << -1 << endl;
    return 0;
}
