// 07. Write a program that ask for base and height of a triangle and computes area.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float base = 0;
	float height = 0;

	printf("Introduce a base: ");
	scanf_s("%f", &base);

	printf("Introduce the height: ");
	scanf_s("%f", &height);

	float area = (base * height) / 2.0f;

	printf("The area of the triangle is %2.2f\n", area);

	return 0;
}