// 03. Write a program that asks for 2 numbers and shows its sum, multiplication, substractio nand division.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number01 = 0;
	int number02 = 0;

	printf("Introduce one value: ");
	scanf_s("%i", &number01);

	printf("Introduce another value: ");
	scanf_s("%i", &number02);

	float mult = number01 * number02;
	float div = number01 / number02;

	printf("The sum of %i and %i is %i\n", number01, number02, number01 + number02);
	printf("The substraction of %i and %i is %i\n", number01, number02, number01 - number02);
	printf("The division of %i and %i is %2.2f\n", number01, number02, mult);
	printf("The division of %i and %i is %2.2f\n", number01, number02, div);

	return 0;
}