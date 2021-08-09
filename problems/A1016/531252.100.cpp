#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int n;
    double a,b,y;
    cin >> n;
    while (--n>=0){
          cin >> a >> b;
          cout << (int)(1+3.14159265358979323846264338327950288*(a*a+b*b)/100.0) << endl;
    }
    //system("pause");
    return 0;
}
