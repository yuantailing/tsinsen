#include <iostream>
using namespace std;
char * GetSubstr(char *sub, char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		j = 0;
		while (sub[j])
		{
			if (str[i + j] != sub[j])
				break;
			++j;
		}
		if (! sub[j])
			return &str[i];
		++i;
	}
	return NULL;
}
int main()
{
	int len_str = 0, len_substr = 0;
	cin >> len_str >> len_substr;
	char* str = new char[len_str + 1];
	for(int i = 0; i < len_str; i++)
	cin >> str[i];
	str[len_str] = '\0';
	char* substr = new char[len_substr + 1];
	for(int i = 0; i < len_substr; i++)
	cin >> substr[i];
	substr[len_substr] = '\0';
	char* c;
	c = GetSubstr(substr, str);
	if (c)
		cout << "find substring:"<<c<<endl;
	else
		cout << "substring not found"<<endl;
	return 0;
}
