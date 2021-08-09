#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int p = M * 6 / 10;
	for (int i = 0; i < N; i++) {
		int count = 0;
		for (int j = 0; j < M; j++) {
			int grade;
			cin >> grade;
			if (grade < 6)
				count++;
		}
		if (count > p)
			cout << "What The Hell" << endl;
		else
			cout << "tada!" << endl;
	}
	//system("pause");
	return 0;
}
