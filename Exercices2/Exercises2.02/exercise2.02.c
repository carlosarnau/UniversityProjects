// 02. Write a program that asks for 2 numbers to the user and determinate the greater one.Take care of side posibilities(equal numbers).

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number01 = 0;
	int number02 = 0;

	printf("Introduce a number: ");
	scanf_s("%i", &number01);

	printf("Introduce another number: ");
	scanf_s("%i", &number02);

	if (number01 > number02)
	{
		printf("The first number you introduced is the greatest\n");
	}
	else if (number01 == number02)
	{
		printf("The two numbers you introduced are equal\n");

	}
	else
	{
		printf("The second number you introduced is the greatest\n");

	}

	return 0;
}