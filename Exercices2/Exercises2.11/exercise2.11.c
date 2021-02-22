// 11. Write a function to check if an integer is negative. Function declaration should be: int IsNegative(int num);

#include <stdio.h>

int main()
{
	int integer = 0;

	printf("Introduce an integer: ");
	scanf_s("%i", &integer);

	if (IsNegative(integer) > 0)
	{
		printf("Your integer is positive");
	}
	else
	{
		printf("Your integer is negative");
	}

	return 0;
}

int IsNegative(int integer)
{
	int door = 0;

	if (integer < 0)
	{
		door = 0;
	}
	else
	{
		door = 1;
	}

	return door;
}