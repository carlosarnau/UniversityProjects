// 10. Write a program that asks for a value in centimeter and convert it into meter and kilometer.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int centimeter = 0;

	printf("Introduce a value in centimeter: ");
	scanf_s("%i", &centimeter);

	int meter = centimeter / 1000;
	int kilometer = centimeter / 100000;

	printf("Your value in meters is %i\n", meter);
	printf("Your value in kilometers is %i\n", kilometer);

	return 0;
}