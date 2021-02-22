// 04. Write a program that asks for 2 numbers and computes the mean.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float number01 = 0;
	float number02 = 0;

	printf("Introduce one value: ");
	scanf_s("%f", &number01);

	printf("Introduce another value: ");
	scanf_s("%f", &number02);

	printf("The mean of %2.2f and %2.2f is %2.2f\n", number01, number02, (number01 + number02) / 2.0f);

	return 0;
}