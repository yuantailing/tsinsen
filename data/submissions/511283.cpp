#include <iostream>
using namespace std;
enum choose
{
	shitou	= 0,
	bu		= 1,
	jiandao	= 2
};
enum results
{
	win		= 1,
	lose	= -1,
	tie		= 0
};
int main(void)
{
	enum choose		playerone;
	enum choose		playertwo;
	enum results	result;
	int			 x;
	cin >> x;
	playerone = (enum choose)x;
	cin >> x;
	playertwo = (enum choose)x;
	switch (playerone)
	{
	case jiandao:
		switch (playertwo)
		{
		case jiandao:
			result = tie;
			break;
		case shitou:
			result = lose;
			break;
		case bu:
			result = win;
			break;
		}
		break;
	case shitou:
		switch (playertwo)
		{
		case jiandao:
			result = win;
			break;
		case shitou:
			result = tie;
			break;
		case bu:
			result = lose;
			break;
		}
		break;
	case bu:
		switch (playertwo)
		{
		case jiandao:
			result = lose;
			break;
		case shitou:
			result = win;
			break;
		case bu:
			result = tie;
			break;
		}
		break;
	}
	cout << (int)result;
	return 0;
}
