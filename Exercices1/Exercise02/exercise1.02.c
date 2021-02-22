// 02. Write a program that asks for 2 numbers and shows the sum.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number01 = 0;
	int number02 = 0;

	printf("Introduce one value: ");
	scanf_s("%i", &number01);

	printf("Introduce another value: ");
	scanf_s("%i", &number02);

	printf("The sum of %i and %i is %i\n", number01, number02, number01 + number02);

	return 0;
}