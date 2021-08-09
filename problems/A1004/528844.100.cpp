#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    for (i=1;i<=n;++i)
    {
        for (j=i;j>=1&&j>i-m;--j)
            printf("%c",'A'-1+j);
        if (i>=m){
                  cout<<endl;
                  continue;
                  }
        for (j=2;j<=m-i+1;++j)
            printf("%c",'A'-1+j);
        cout<<endl;
    }
    //system("pause");
    return 0;
}
