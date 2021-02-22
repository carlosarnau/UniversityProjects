// Write a program that ask for 3 articles and apply a 15 % discount offer to the total buying prize.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float article1 = 0;
	float article2 = 0;
	float article3 = 0;

	printf("Introduce the prize of the first item: ");
	scanf_s("%f", &article1);
	printf("Introduce the prize of the second item: "),
	scanf_s("%f", &article2);
	printf("Introduce the prize of the third item: ");
	scanf_s("%f", &article3);

	float total_prize = article1 + article2 + article3;
	float discount = total_prize *0.15f;
	total_prize -= discount;

	printf("The final price of your 3 products is %2.2f\n", total_prize);

	return 0;
}