#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
    int i,j,k,n,m;
    char p[100009];
    char *a;
    int b[100009];
    int c,d;
    int buf,tmp;
    cin >> buf;
for (tmp=0;tmp<buf;++tmp){
    a=p;
    a[0]=a[1]=a[2]=a[3]='0';
    a=&p[3];
    //scanf("%s",&a[2-((n-1)%3)]);
    scanf("%s",a);
    n=strlen(a);
    a=&p[1+((n-1)%3)];
    m=(n+2)/3;
    for (i=0;i<100000;++i){
        if (a[i]<='9') b[i]=a[i]-'0';
        else b[i]=a[i]-'A'+10;
    }
    for (i=0;i<m*3;i+=3){
        c=b[i]*16*16+b[i+1]*16+b[i+2];
        d=c/8/8/8*1000+(c/8/8)%8*100+(c/8)%8*10+c%8;
        cout << d;
    }
    cout << endl;
}
    //system("pause");
    return 0;
}