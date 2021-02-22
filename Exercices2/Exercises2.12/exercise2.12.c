// 12. Write a function to calculate power of a value. Function declaration should be: int RaiseToPower(int value, int power);

#include <stdio.h>

int RaierToPower(int value, int power)
{
	int result = 1;

	while (power > 0)
	{
		result *= value;
		power--;
	}

	return result;
}

int main()
{
	int base = 0;
	int power = 0;

	printf("Introduce a value to calcute her power: ");
	scanf_s("%i", &base);
	printf("Introduce the power you want to elevate the value: ");
	scanf_s("%i", &power);

	printf("The power of your value is %i", RaierToPower(base, power));

	return 0;
}