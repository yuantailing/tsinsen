#include <iostream>
using namespace std;
int main(void)
{
	int a,b;
	char c;
	int answer;
	cin >> a;
	cin >> c;
	cin >> b;
	switch (c)
	{
		case '+': answer = a + b; break;
		case '-': answer = a - b; break;
		case '*': answer = a * b; break;
		case '/': answer = a / b; break;
		case '%': answer = a % b; break;
		default : answer = 0; break;
	}
	cout << answer << endl;
	return 0;
}
