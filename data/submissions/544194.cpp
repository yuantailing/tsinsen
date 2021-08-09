#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <assert.h>
using namespace std;

class Time{
public:
    int h,m,s;
    Time(int hh,int mm,int ss){
        h=hh;m=mm;s=ss;}
    void adv(int hh,int mm,int ss);
    void print(){
        printf("%02d:%02d:%02d\n",h,m,s);}
    void reset(){
        h=m=s=0;}
};
void Time::adv(int hh,int mm,int ss){
    h+=hh;m+=mm;s+=ss;
    while (s<0) {m-=1;s+=60;}
    while (s>59){m+=1;s-=60;}
    while (m<0) {h-=1;m+=60;}
    while (m>59){h+=1;m-=60;}
    while (h<0) h+=24;
    while (h>23) h-=24;
}

int main()
{ 
	// 当前时间
	int hour, minute, second;
	// 时间增量
	int incr_hr, incr_min, incr_sec;
	
	cin >> hour >> minute >> second >> incr_hr >> incr_min >> incr_sec;

	Time t( hour, minute, second );
  	t.print();

  	t.adv( incr_hr, incr_min, incr_sec );
  	t.print();

	t.reset();
	t.print();

  	return 0;
}
