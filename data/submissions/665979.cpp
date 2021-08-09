#include <iostream>

using namespace std;

struct position {
	int x;
	int y;
};

void psort(position ps[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            if (ps[i].x > ps[j].x || (ps[i].x == ps[j].x && ps[i].y>ps[j].y)) {
                position t = ps[i];
                ps[i] = ps[j];
                ps[j] = t;
            }
        }
}

const int maxn = 100;
position points[maxn];
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> points[i].x >> points[i].y;
	psort(points, n);
	for (int i = 0; i < n; ++i)
		cout << points[i].x << " " << points[i].y << endl;
	return 0;
}
