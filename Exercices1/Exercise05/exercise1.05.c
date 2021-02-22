// 05. Write a program that ask for an ageand computes the number of pulses a person should have after 10 seconds of training.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float age = 0;

	printf("Introduce your age: ");
	scanf_s("%f", &age);

	float pulses = (220.0f - age) / 10.0f;

	printf("Your number of pulses after 10 seconds of training should be %2.2f\n", pulses);

	return 0;
}