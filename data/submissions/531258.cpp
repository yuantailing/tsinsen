#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
using namespace std;
int cmp(const void*a,const void*b){
    if (*(int*)a>*(int*)b) return 1;
    else if (*(int*)a<*(int*)b) return -1;
    return 0;
}
int main()
{
    int n,i;
    int a[200];
    cin >> n;
    assert(1<=n&&n<=200);
    for (i=0;i<n;++i) cin >> a[i];
    qsort(a,n,sizeof(int),cmp);
    for (i=0;i<n;++i) cout << a[i] << ' ';
    //system("pause");
    return 0;
}
