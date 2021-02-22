// 13. Write a program that ask for a value and computes the 21% of IVA over that value.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float value = 0;
	
	printf("Write the price of your product: ");
	scanf_s("%f", &value);

	float result = value / 100;
	result *= 21;

	printf("The IVA of your product is %2.2f\n", result);

	return 0;
}
