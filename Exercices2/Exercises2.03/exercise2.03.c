// 03. Write a program that asks for 3 numbers to the user and determinate the greater one.Take care of side posibilities(equal numbers).

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number01 = 0;
	int number02 = 0;
	int number03 = 0;

	printf("Introduce a number: ");
	scanf_s("%i", &number01);

	printf("Introduce another number: ");
	scanf_s("%i", &number02);

	printf("Introduce another number: ");
	scanf_s("%i", &number03);

	if ((number01 > number02) && (number01 > number03))
	{
		printf("The first number you introduced is the greatest.\n");
	}
	else if ((number02 > number01) && (number02 > number03))
	{
		printf("The second number you introduced is the greatest.\n");
	}
	else if ((number03 > number01) && (number03 > number02))
	{
		printf("The third number you introduced is the greatest.\n");
	}
	else
	{
		if ((number01 == number02) && (number01 > number03))
		{
			printf("The first and the second value you introduced are the same.\n");
		}
		else if ((number02 == number03) && (number02 > number01))
		{
			printf("The second and the third value you introduced are the same.\n");
		}
		else if ((number03 == number01) && (number03 > number02))
		{
			printf("The first and the third value you introduced are the same.\n");
		}
		else
		{
			printf("The three values you introduced are the same.\n");
		}
	}

	return 0;
}