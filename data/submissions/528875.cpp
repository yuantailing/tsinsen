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
    char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int n;
    cin>>n;
    cout<<a[n/16]<<a[n%16]; 
    //system("pause");
    return 0;
}
