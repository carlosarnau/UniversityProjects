// 09. Write a program that asks for a sequence of numbers to the user and show the sum of all of them. Process stops when 0 is introduced.

#include <stdio.h>		// Required for: printf(), scanf() 

int main()
{
	int system = 1;
	int n = 0;
	int myMatriz1[100][1];
	int x = 0;
	int y = 0;
	int counter = 0;
	char sums;

	while (system == 1)
	{
		printf("Introduce a number: ");
		scanf_s("%i", &n);
		myMatriz1[x][y] = n;

		if (n == 0)
		{
			printf("The final sum of the numbers you introduced is %i\n", counter);
			x--;
			while (x >= 0)
			{
				printf("%i ", myMatriz1[x][y]);
				if (x > 0)
				{
					printf("+ ");
				}
				else
				{
					printf("= %i", counter);
				}
				x--;
			}
			system = 0;
		}
		else
		{
			counter += myMatriz1[x][y];
			x++;
		}
	}

	return 0;
}