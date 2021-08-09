#include <iostream>
#include <cstring>
using namespace std;

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
	return 0;
}
