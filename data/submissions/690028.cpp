#include <iostream>
using namespace std;

int main()
{
    int m, n, a;
    int k = 0;   //count #students who fail
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = 0; j < m; j++)
        {
            cin >> a;   //read in the score of one student
            if (a < 6)
                k++;
        }
        if (k * 10 > 6 * m)
            cout << "What The Hell" << endl;
        else
            cout << "tada!" << endl;
    }
    return 0;
}
