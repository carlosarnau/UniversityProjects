// 12. Write a program that ask of a value in centimeters and computes the inch equivalent.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float centimeters = 0;

	printf("Introduce a value in centimeters: ");
	scanf_s("%f", &centimeters);

	float inch = centimeters / 2.54f;
	
	printf("Your centimeter value in inches is equal to %2.2f inches\n", inch);

	return 0;
}