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
int main(){
	int a[1001],b[1001],c[2002];
	int n,m,flag;
	int i,j,k;
	cin>>n;
	for (int i=0;i<n;++i) cin>>a[i];
	cin>>m;
	for (int i=0;i<m;++i) cin>>b[i];

	for (i=j=k=0;i<n;++i){
		for (j=0;j<m;++j){
			if (a[i]==b[j]){
				c[k++]=a[i];
				break;
			}
		}
	}
	qsort(c,k,sizeof(int),cmp);
	for (int i=0;i<k;++i){
		cout<<c[i];
		if (i<k-1) cout<<' ';
		else cout<<endl;
	}

	for (i=0;i<n;++i) c[i]=a[i];
	for (i=0,k=n;i<m;++i){
		flag=1;
		for (j=0;j<n;++j){
			if (a[j]==b[i]){
				flag=0;
				break;
			}
		}
		if (flag) c[k++]=b[i];
	}
	qsort(c,k,sizeof(int),cmp);
	for (int i=0;i<k;++i){
		cout<<c[i];
		if (i<k-1) cout<<' ';
		else cout<<endl;
	}

	for (i=k=0;i<n;++i){
		flag=1;
		for (j=0;j<m;++j){
			if (a[i]==b[j]){
				flag=0;
				break;
			}
		}
		if (flag) c[k++]=a[i];
	}
	qsort(c,k,sizeof(int),cmp);
	for (int i=0;i<k;++i){
		cout<<c[i];
		if (i<k-1) cout<<' ';
		else cout<<endl;
	}

	//system("pause");
	return 0;
}
