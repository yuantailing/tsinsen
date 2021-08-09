#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int main()
{
    int times;
    int i,j,ddd;
    cin >> times;
    for (ddd=0;ddd<times;++ddd){
        char a[100001];
        int b[100001];
        int c[400004];
        int d[200002];
        int p=0;
        memset(a,'0',sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
        scanf("%s",a);
        int len=strlen(a);
        for (i=0;i<len;++i){
            if (a[i]<='9') b[i]=a[i]-'0';
            else b[i]=a[i]-'A'+10;
            c[i*4]=b[i]/8;
            c[i*4+1]=(b[i]/4)%2;
            c[i*4+2]=(b[i]/2)%2;
            c[i*4+3]=(b[i]/1)%2;
        }
        for (i=len*4-1;i>=2;i-=3){
            d[p]=c[i-2]*4+c[i-1]*2+c[i];
            ++p;
        }
        if (i==1) d[p]=c[i-1]*2+c[i];
        else if (i==0) d[p]=c[i];
        while (!d[p]) --p;
        for (;p>=0;--p)
            cout << d[p];
        cout << endl;
    }
    //system("pause");
    return 0;
}
