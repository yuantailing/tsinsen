#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int i,j;
    for (i=10;i<100;++i)
    {
        j=n-2*((i/10)+(i%10));
        if (j>=0&&j<=9)
            printf("%d%d%d%d\n",i,j,i%10,i/10);
    }
    if (n%2==0)
    for (i=10;i<100;i++)
    {
        j=n/2-((i/10)+(i%10));
        if (j>=0&&j<=9)
            printf("%d%d%d%d%d\n",i,j,j,i%10,i/10);
    }
    //system("pause");
    return 0;
}
