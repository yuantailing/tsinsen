#include <iostream>
#include <cstring>
using namespace std;

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
