#include <iostream>
using namespace std;

int main()
{
string a;
string b;
cin >> a;
cin >> b;
if (a > b)
cout << 1;
else if (a == b)
cout << 0;
else
cout << -1;
return 0;
}
