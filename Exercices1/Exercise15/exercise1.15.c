// 15. Write a program that asks for seconds and convert it into minutes, hours and days.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float seconds = 0;
	float minutes = 0;
	float hours = 0;
	float days = 0;

	printf("Introduce a number of seconds: ");
	scanf_s("%f", &seconds);

	minutes = seconds / 60.00f;
	hours = minutes / 60.00f;
	days = hours / 24.00f;

	printf("The number of seconds you introduced in minutes are %2.2f, in hours %2.2f, and in days %2.2f\n", minutes, hours, days);

	return 0;
}
