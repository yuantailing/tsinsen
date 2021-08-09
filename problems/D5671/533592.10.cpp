#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
using namespace std;
int main()
{
    int i,j,k,n,a,b;
    int y[100];
    n=13;
    y[0]=1;
    for (i=0;i<n;++i){
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
