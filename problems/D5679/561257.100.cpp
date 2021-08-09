#include <iostream>
#include <cmath>
using namespace std;

void sieve(bool isPrime[], int n){

    for (int i = 2; i < n; i ++){
        isPrime[i] = true;

        int m = sqrt(double(i));

        for (int j = 2; j <= m; j ++){
            if (i % j == 0){
                isPrime[i] = false;
                break;
            }
        }
    }
}

void Disp(bool a[], int n)
{
    for (int i = 1; i < n; i++){
        if (a[i]) {
            cout << i << " " ;
        }
    }
    cout<<endl;
}
int main()
{
    int n = 0;
    cin >> n;
    if (n < 2)
        return 0;
    bool* isPrime = new bool[n];

    isPrime[0] = false;
    isPrime[1] = false;

    sieve(isPrime,n);
    Disp(isPrime,n);
    return 0;
}
