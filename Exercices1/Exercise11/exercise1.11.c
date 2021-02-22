// 11. Write a program that asks for a temperature in Celsius(°C) and convert it into Fahrenheit(°F).

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float celsius = 0;

	printf("Introduce a temperature in Celsius: ");
	scanf_s("%f", &celsius);

	float fahrenheit = (((celsius * 9) / 5) + 32);

	printf("Your temperature in fahrenheit is %2.2f\n", fahrenheit);

	return 0;
}