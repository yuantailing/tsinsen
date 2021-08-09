#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
FILE*fp;
int maxnum;
int sum;
int work(){
    int i=0;
    int men=(int)((double)maxnum*2/log(maxnum));
    int*p=NULL;
    int*q=NULL;
    p=(int*)malloc(men*sizeof(int));
    for (i=0;i<men;++i) p[i]=2147483647;
    *p=2;
    int a=1,t=0,n=1,s=0;
    while ((a+=2)<=maxnum){
          s=1;
          t=(int)sqrt(a+1);
          {
              q=p;
              while(*q<=t){
                           if (a%(*q)==0){
                                          s=0;
                                          break;
                                          }
                           ++q;
                           }
          }
          if (s==1){
             sum+=a;
             ++n;
             p[n-1]=a;
             }
          }
}

int main(){
    do{
    sum=0;
    cin>>maxnum;
    if (maxnum>=2) sum+=2;
    fp=NULL;
    work();
    cout<<sum;
    }
    while (maxnum>0);
    return(0);
}
