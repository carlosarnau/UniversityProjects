// 01 . Write a program that asks for a maximum numberand shows all multiples of 3 between 1 and that number.

#include <stdio.h>

int main()
{
	int counter = 0;
	int multiple = 0;

	printf("Introduce a number:");
	scanf_s("%i", &counter);

	int inicial = counter - counter + 1;

	while (inicial <= counter)
	{
		multiple = 3 * inicial;
		printf("%i, ", multiple);
		inicial++;
	}

	return 0;
}