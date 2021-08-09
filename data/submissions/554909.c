#include <stdio.h>
int main()
{
int a,x,b,j,i=0,y=0;
int normalmonth[12]={0,31,28,31,30,31,30,31,31,30,31,30};
int specialmonth[12]={0,31,29,31,30,31,30,31,31,30,31,30};
scanf("%d",&x);
for(a=1998;a<x;a++)
{if(((a%4==0)&&(a%100!=0))||(a%400==0)) i++;}
b=13+(x-1998)*365+i;
if(((x%4==0)&&(x%100!=0))||(x%400==0)) 
{for(j=0;j<=11;j++){b=b+specialmonth[j];
if(b%7==2) y++; }
}
else {for(j=0;j<=11;j++){b=b+normalmonth[j];if(b%7==2) y++; }}
printf("%d",y);
}
