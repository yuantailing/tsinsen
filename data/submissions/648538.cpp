/*************************************************************************
	> File Name: four.cpp
	> Created Time: Wednesday, October 09, 2013 PM10:13:05 HKT
	> Author: Wayne Ho
	> Mail: hewr2010@gmail.com 
 ************************************************************************/
#include <iostream>
#include <cstdio>
using namespace std;

void process(char* str, int l, int r) {
	    char ch = 'z';
	for (int i = l; i <= r; i++)
		if (str[i-1] < ch)
			ch = str[i-1];
	for (int i = l; i <= r; i++) {
		str[i-1] = ch;
		ch++;
		if (ch > 'z')
			ch = 'a';
	}
}

int main(){
	string S;
	cin >> S;
	char* str = new char[S.length() + 1];
	sprintf(str, "%s", S.c_str());
	int n;
	cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		process(str, l, r);
	}
	cout << str << endl;
	delete[] str;

    return 0;
}
