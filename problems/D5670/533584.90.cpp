#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
using namespace std;
bool isTriangular( int n )
{
    int i=0;
    int m=0;
    while (++i){
          m+=i;
          if (m==n) return true;
          if (m>n) return false;
    }
}
int main()
{
    int min_val, max_val;
    //请输入区间端点（例如若指定区间[10, 30]，则输入10 30）
    cin >> min_val >> max_val;
    if( min_val > max_val )
    {
    int x = min_val; min_val = max_val; max_val = x;
    }
    for( int i = max( 0, min_val ); i <= max_val; ++i )
    if( isTriangular(i) )
    cout << i << " is a triangular number." << endl;
    return 0;
}
