#include <iostream>

using namespace std;

struct position {
	int x;
	int y;
};

void psort(position ps[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
			if (ps[j].x > ps[j+1].x || (ps[j].x == ps[j+1].x && ps[j].y > ps[j+1].y))
			{
				position t = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = t;
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
