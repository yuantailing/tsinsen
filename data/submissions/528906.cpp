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
    char c[36];
    int a,b,buf,t;
    int n=0,i,j;
    for (i=0;i<=9;++i) c[i]='0'+i;
    for (i=10;i<=35;++i) c[i]='A'+i-10;
    cin >> a >> t;
    b=a;
    while (b>=t){
          b/=t;
          ++n;
    }
    b=a;
    for (i=n;i>0;--i){
        buf=1;
        for (j=0;j<i;++j)
            buf*=t;
        cout<<c[b/buf];
        b-=b/buf*buf;
    }
    cout<<c[b];
    //system("pause");
    return 0;
}
