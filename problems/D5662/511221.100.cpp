#include <iostream>
using namespace std;
int main(void)
{
	char	c[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
	int		i;
	for (i = 0; i < 10; ++i)
		cout << (int)c[i] << endl;
	return 0;
}
