// 05. Write a program that asks for a character and determines if is a vowel a consonant or none of them.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	char letter = 0;

	printf("Introduce a character: ");
	scanf_s("%c", &letter, 1);

	if (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z')
	{
		if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' ||
			letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
		{
			printf("\n%c is a vowel.\n", letter);
		}
		else
		{
			printf("\n%c is a consonant.\n", letter);
		}
	}
	else
	{
		printf("\n%c is not a letter.\n", letter);
	}

	return 0;
}