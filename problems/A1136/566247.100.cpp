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
	double t=q1+1;
	double q3=q1;
	while (q3-q1<1||q2-q3<1){
		q3=s(t++);
	}
	printf("%.2lf %.2lf %.2lf",q1,q3,q2);
	return 0;
}
















/*
//数的划分
int n;
int k;
int d[201][7][101];

int divide(int n,int k,int m);
int divide(int n,int k,int m){
	int sum=0;
	int t=d[n][k][m];
	if (t>=0) return t;
	for (int i=m;i<=n/k;++i){
		{
			sum+=divide(n-i,k-1,i);
		}
	}
	dok:
	d[n][k][m]=sum;
	return sum;

}

int main(){
	cin>>n;
	cin>>k;
	for (int i=0;i<201;++i)
		for (int j=0;j<7;++j)
			for (int k=0;k<101;++k){
				d[i][j][k]=-1;
			}
	for (int i=0;i<201;++i){
		for (int j=0;j<101;++j){
			if (i>=j) d[i][1][j]=1;
			else d[i][1][j]=0;
		}
	}
	cout<<divide(n,k,1);
	system("pause");
	return 0;
}
*/




/*装箱问题
int main(){
	int v;
	int n;
	int a[30000];
	int b;
	memset(a,0,sizeof(a));
	a[0]=1;
	cin>>v;
	if (v<=0){
		cout<<0;
		return 0;
	}
	cin>>n;
	if (n<=0){
		cout<<v;
		return 0;
	}
	for (int j=0;j<n;++j){
		cin>>b;
		for (int k=v-b;k>=0;--k)
			if (a[k])
				a[k+b]=1;
	}
	int m=0;
	while (!a[v-m]) ++m;
	cout<<m;
	return 0;	
}
*/