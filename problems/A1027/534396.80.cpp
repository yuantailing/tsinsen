#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
int cmp(const void *a, const void *b){
	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a > *(int*)b) return -1;
	return 0;
}
int gcd(int a, int b){
	if (a % b == 0) return b;
	else return (gcd(b, a % b));
}
int main(){
	int i,j,k;
	int n;
	int flag=0;
	char a[21],b[21];
	cin>>a;
	cin>>n;
	for (i=0;i<n;++i){
		cin>>b;
		char*c=a,*d=b;
		int buf=1;

		buf=1;
		c=a;
		d=b;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		if ((c-a)==strlen(a)&&(d-b)==strlen(b)){
			flag=1;
			cout<<b;
			return 0;
		}
		

		buf=1;
		c=a;
		d=b;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		++c;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		if ((c-a)==strlen(a)&&(d-b)==strlen(b)){
			flag=1;
			cout<<b;
			return 0;
		}

		buf=1;
		c=a;
		d=b;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		++d;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		if ((c-a)==strlen(a)&&(d-b)==strlen(b)){
			flag=1;
			cout<<b;
			return 0;
		}

		buf=1;
		c=a;
		d=b;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		++c;
		++d;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		if ((c-a)==strlen(a)&&(d-b)==strlen(b)){
			flag=1;
			cout<<b;
			return 0;
		}

		buf=1;
		c=a;
		d=b;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		++c;
		++d;
		while (*c){
			if (*c==*d){
				++c;
				++d;
			}
			else break;
		}
		if ((c-a)>strlen(a)-1&&(d-b)>strlen(b)-1){
			flag=1;
			cout<<b;
			return 0;
		}
	
	}

	if (!flag) cout<<"NOANSWER";
	//system("pause");
	return 0;
}
