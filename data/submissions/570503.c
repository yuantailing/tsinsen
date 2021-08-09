#include <stdio.h>
#include <string.h>

int fn1(int a, int b)
{
	return a + b;
}
int fn2(int a, int b)
{
	return a - b;
}
int fn3(int a, int b)
{
	return a * b;
}
int fn4(int a, int b)
{
	return a / b;
}

int main()
{
	char ch;
	int a;
	int b;
	int c = 0;
	scanf("%c%d%d", &ch, &a, &b);
	switch (ch)
	{
	case '+':
		c = fn1(a, b);
		break;
	case '-':
		c = fn2(a, b);
		break;
	case '*':
		c = fn3(a, b);
		break;
	case '/':
		c = fn4(a, b);
		break;
	}
	printf("%d",c);
	return 0;
}
