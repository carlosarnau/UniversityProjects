// 08. Write a program that asks for 10 numbers to the user and show the sum and product of all of them.Use while loop.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int n7 = 0;
	int n8 = 0;
	int n9 = 0;
	int n10 = 0;

	printf("\nIntroduce a number: ");
	scanf_s("%i", &n1);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n2);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n3);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n4);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n5);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n6);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n7);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n8);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n9);
	printf("\nIntroduce a number: ");
	scanf_s("%i", &n10);
	printf("\n");

	int myMatriz1[10][1] = { {n1},{n2},{n3},{n4},{n5},{n6},{n7},{n8},{n9},{n10} };
	int myMatriz2[10][1] = { {n1},{n2},{n3},{n4},{n5},{n6},{n7},{n8},{n9},{n10} };
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int list_item1 = 10;
	int list_item2 = 10;
	int sum = 0;
	int product = 0;

	while ((list_item1 > 0) && (x1 < 10))
	{
		sum = sum + myMatriz1[x1][y1];
		printf("%i", myMatriz1[x1][y1]);
		if (list_item1 > 1)
		{
			printf(" + ");
		}
		else
		{
			printf(" = ");
		}
		x1++;
		list_item1--;
	}
	printf("%i\n\n", sum);

	product = 1;

	while ((list_item2 > 0) && (x2 < 10))
	{
		product = product * myMatriz2[x2][y2];
		printf("%i", myMatriz2[x2][y2]);
		if (list_item2 > 1)
		{
			printf(" * ");
		}
		else
		{
			printf(" = ");
		}
		x2++;
		list_item2--;
	}
	printf("%i\n", product);

	return 0;
}