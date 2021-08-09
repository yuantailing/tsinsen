#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
/*
vector<int> v;

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
			v.push_back(v[j]+w);
			v.push_back(v[j]-w);
		}
		//sort(v.begin(), v.end());
		//unique(v.begin(), v.end());
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
*/


int *v;
int size;

int main()
{
	int n, m;
	cin >> n >> m;
	v = new int[60*1024*1024];
	v[size++] = 0;
	for (int i = 0; i < n; i++) {
		int w;
		cin >> w;
		int s = size;
		for (int j = 0; j < s; j++) {
			v[size++] = (v[j]+w);
			v[size++] = (v[j]-w);
		}
	}
	for (int i = 0; i < m; i++){
		int w;
		cin >> w;
		int s = size;
		int j;
		for (j = 0; j < s; j++)
			if (v[j] == w) {
				cout << "YES" << endl;
				break;
			}
		if (j == size)
			cout << "NO" << endl;
	}
	return 0;
}

