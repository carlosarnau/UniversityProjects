// 03. Write a program that asks a birth date and calculates age in days, hours and minutes. -> Required:time()

#include <stdio.h>

int main()
{
	int byear = 0;
	int bmonth = 0;
	int bday = 0;
	int year_today = 0;
	int month_today = 0;
	int day_today = 0;


	printf("Introduce your birthday (DD/MM/YYYY): ");
	scanf_s("%i/%i/%i", &bday, &bmonth, &byear);

	printf("Introduce todays date (DD/MM/YYYY): ");
	scanf_s("%i/%i/%i", &day_today, &month_today, &year_today);

	int y = year_today - byear - 1;
	int m = (12 - (bmonth - 1)) + (12 - (month_today - 1));
	int d = 30 - bday + day_today;
	int counter = (365 * y) + (30 * m) + d;

	printf("Your age in days is %i", counter);

	return 0;
}