// 01. Write a program that asks for a numberand determines if the number is even or odd.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number = 0;
	int reminder = 0;

	printf("Introduce a number: ");
	scanf_s("%i", &number);

	if ((reminder % 2) == 0)
	{
		printf("THe number is even\n");
	}
	else
	{
		printf("The number is odd \n");

	}

	return 0;
}