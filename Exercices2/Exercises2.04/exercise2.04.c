// 04. Write a program that asks for a month number and shows the number of days and name of the month.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int month_number = 0;

	printf("Introduce a month number: ");
	scanf_s("%i", &month_number);

	if ((month_number < 13) && (month_number > 0))
	{
		if (month_number == 1)
		{
			printf("The month you are searching is January with 31 days\n");
		}
		else if (month_number == 2)
		{
			printf("The month you are searching is February with 28 days\n");
		}
		else if (month_number == 3)
		{
			printf("The month you are searching is March with 31 days\n");
		}
		else if (month_number == 4)
		{
			printf("The month you are searching is April with 30 days\n");

		}
		else if (month_number == 5)
		{
			printf("The month you are searching is May with 31 days\n");

		}
		else if (month_number == 6)
		{
			printf("The month you are searching is June with 30 days\n");

		}
		else if (month_number == 7)
		{
			printf("The month you are searching is July with 31 days\n");

		}
		else if (month_number == 8)
		{
			printf("The month you are searching is August with 31 days\n");

		}
		else if (month_number == 9)
		{
			printf("The month you are searching is Septmeber with 30 days\n");

		}
		else if (month_number == 10)
		{
			printf("The month you are searching is October with 31 days\n");

		}
		else if (month_number == 11)
		{
			printf("The month you are searching is November with 30 days\n");
		}
		else if (month_number == 12)
		{
			printf("The month you are searching is December with 31 days\n");
		}
	}

	else
	{
		printf("The number you introduced is incorrect!\n");
	}

	return 0;
}