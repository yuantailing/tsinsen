#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//一元三次方程求解
double delta=0.001;
double a,b,c,d;
inline double f(double x){
	return a*x*x*x+b*x*x+c*x+d;
}
inline double g(double x){
	return 3*a*x*x+2*b*x+c;
}

double s(double p);
double s(double p){
	if (f(p)*f(p+delta)<0) return p;
	else if (f(p)*f(p-delta)<0) return p;
	else return s(p-f(p)/g(p));
}

int main(){
	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	double q1=s(-100.0);
	double q2=s(100.0);
	double q3=s((q1+q2)/2);
	printf("%.2lf %.2lf %.2lf",q1,q3,q2);
	return 0;
}