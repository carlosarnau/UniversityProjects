// 02. Write a program that displays the first 100 prime numbers.

#include <stdio.h>

int main()
{
	int number = 2;

	if (number < 4)
	{
		printf("%i, ", number);
		number++;
	}
	while (number < 101)
	{
		printf("%i, ", number);
		number = number + 2;
	}
}