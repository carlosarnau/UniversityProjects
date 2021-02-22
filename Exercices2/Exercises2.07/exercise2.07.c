// 07. Write a program that asks for 2 numbers to the user and show product by sums. Use while loop.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int number01 = 0;
	int number02 = 0;
	int product = 0;

	printf("Introduce a number: ");
	scanf_s("%i", &number01);

	printf("Introduce a number: ");
	scanf_s("%i", &number02);

	while (number02 > 0)
	{
		product += number01;
		printf("%i", number01);
		if (number02 >= 2)
		{
			printf("+");
		}
		else
		{
			printf(" = %i", product);
		}
		number02--;
	}

	return 0;
}