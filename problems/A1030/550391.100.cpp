#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
struct Team{
	char name[21];
	int fen;
	int win;
	int jin;
};


int cmp(void const *aa, void const *bb){
	Team a = *(Team*)aa;
	Team b = *(Team*)bb;
	int c;
	if (a.fen>b.fen) return 1;
	else if (a.fen<b.fen) return -1;
	if (a.win>b.win) return 1;
	else if (a.win<b.win) return -1;
	if (a.jin>b.jin) return 1;
	else if (a.jin<b.jin) return -1;
	c=strcmp(a.name,b.name);
	if (c>0) return -1;
	else if (c<0) return 1;
	return 0;
}


int main(){
	int n;
	int i;
	Team t[11];
	cin>>n;
	for (i=0;i<n;++i)
		cin>>t[i].name>>t[i].fen>>t[i].win>>t[i].jin;
	qsort(t,n,sizeof(Team),cmp);
	for (i=n-1;i>=0;--i)
		cout<<t[i].name<<endl;
	return 0;
}
