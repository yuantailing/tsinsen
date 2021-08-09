#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
    int i,j,k,n,a,b;
    int y[100];
    cin >> n;
    for (i=0;i<n;++i){
        y[0]=1;
        for (j=i-1;j>0;--j)
            y[j]=y[j-1]+y[j];
        y[i]=1;
        for (j=0;j<=i;++j)
            cout << y[j] << ' ';
        cout << endl;
    }
    //system("pause");
    return 0;
}
