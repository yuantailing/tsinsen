#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int cmp(const void*a,const void*b){
	if (*(int*)a>*(int*)b) return 1;
	else if (*(int*)a>*(int*)b) return -1;
	return 0;
}

int v[11][11][2];
int f(int a,int b,int c){
	if (a<0) return 0;
	if (b<0) return 0;
	if (c<0) return 0;
	return v[a][b][c];
}

int main(){
	int i,j,k;
	int n;
	int sum;
	cin>>n;
	memset(v,0,sizeof(v));
	v[0][0][0]=1;
	v[1][1][1]=1;
	for (i=2;i<=n;++i){
		for (j=0;j<n;++j){
			v[i][j][0]=f(i-2,j,1)+f(i-2,j,0)+f(i-3,j,1)+f(i-3,j,0);
			v[i][j][1]=f(i-1,j-1,0);
		}
	}
	
	for (i=sum=0;i<n;++i) sum+=v[n][i][0]+v[n][i][1];
	cout << sum << endl;
	
	for (i=sum=0;i<n;++i) sum+=(v[n][i][0]+v[n][i][1])*i;
	cout << sum;
	//system("pause");
	return 0;
}
