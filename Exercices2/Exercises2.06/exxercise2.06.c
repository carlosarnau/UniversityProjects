// 06. Write a program that asks for 1 number to the user and show its multiply table.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number = 0;
	int counter = 10;

	printf("Introduce a number: ");
	scanf_s("%i", &number);

	while ((counter >= 0) && (counter <= 10))
	{
		printf("%i * %i = %i\n", number, counter, number * counter);

		counter--;
	}

	return 0;
}