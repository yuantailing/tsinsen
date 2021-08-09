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
    int a[101];
    int n,i,j;
    cin>>n;
    for (i=0;i<n;++i) cin>>a[i];
    qsort(a,n,sizeof(int),comp);
    printf("%d\n%d\n%d",a[1],a[n-2],a[1]*a[1]+a[n-2]*a[n-2]);
    //system("pause");
    return 0;
}
