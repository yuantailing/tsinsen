#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int comp(const void*a,const void*b)
{
    if (*(int*)a>*(int*)b) return 1;
    else if (*(int*)a<*(int*)b) return -1;
    return 0;
}
int main()
{
    char c[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int a,b,buf;
    cin >> a;
    b=a;
    int n=0,i,j;
    while (b>=16){
          b/=16;
          ++n;
    }
    b=a;
    for (i=n;i>0;--i){
        buf=1;
        for (j=0;j<i;++j)
            buf*=16;
        cout<<c[b/buf];
        b-=b/buf*buf;
    }
    cout<<c[b];
    //system("pause");
    return 0;
}
