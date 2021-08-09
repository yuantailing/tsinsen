#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <conio.h>

int leapyear(int year)
{
	if (year % 4 != 0) return 0;
	if (year % 400 == 0) return 1;
	if (year % 100 == 0) return 0;
	return 1;
}

int yearday(int year)
{
	if (leapyear(year)) return 366;
	return 365;
}

int monthday(int year, int month)
{
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		case 2:
			if (leapyear(year))
				return 29;
			else
				return 28;
			break;
		default:
 			break;
	};
}

int main(int argc, char *argv[])
{
	int year, days, i, n;
	days = n = 0;
	scanf("%d", &year);
	for (i = 1998; i < year; ++i)
		days += yearday(i);
	days += 12;
	for (i = 1; i <= 12; ++i){
		if (days % 7 == 1)
			++n;
		days += monthday(year, i);
	}
	printf("%d",n);
	//system("pause");
	return 0;
}
