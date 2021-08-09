#include <stdio.h>
int main()
{
    int y,m,d,e,x;
    int s,c,leap;
    int day31,day30,day28;
    d=13;
    e=0;
    scanf("%d", &y);
    if((y%4==0&&y%100!=0)||(y%400==0))
        leap=1;
    else
        leap=0;
    for(m=1;m<=12;m++)
    {
    if(m==1)
        day31=day30=day28=0;
    else if(m==2)
    {
        day31=1;
        day30=day28=0;
    }
    else if(m<=8)
    {
        day31=m/2;
        day28=1;
        day30=m-1-day31-day28;
    }
    else
    {
        day31=(m+1)/2;
        day28=1;
        day30=m-1-day31-day28;
    }
    c=day31*31+day28*28+day30*30+d;
    if(m>2&&leap) c++;
    s=y-1+(y-1)/4-(y-1)/100+(y-1)/400+c;
    x=s%7;
    if(x==5) e++;
    }
    printf("%d\n",e);
}
