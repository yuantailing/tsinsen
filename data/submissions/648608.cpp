#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> v;

void push(int w) {
	int size = v.size();
	for (int i = 0; i < size; i++)
		if (v[i] == w)
			return;
	v.push_back(w);
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		int size = v.size();
		for (int j = 0; j < size; j++) {
			push(v[j]+w);
			//push(v[j]-w);
		}
	}
	for (int i = 0; i < m; i++){
		int w;
		cin >> w;
		int size = v.size();
		int j;
		for (j = 0; j < size; j++)
			if (v[j] == w) {
				cout << "YES" << endl;
				break;
			}
		if (j == size)
			cout << "NO" << endl;
	}
	system("pause");
	return 0;
}
