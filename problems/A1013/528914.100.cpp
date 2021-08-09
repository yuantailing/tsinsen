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
    long long a;
    cin>>hex>>a;
    cout<<dec<<a;
    //system("pause");
    return 0;
}
