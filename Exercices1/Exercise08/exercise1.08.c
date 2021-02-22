// 08. Write a program that asks for radius of a circle and find its diameter, circunference and area.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float radius = 0;
	const float pi = 3.14159265359f;

	printf("Introduce a radius: ");
	scanf_s("%f", &radius);

	float diameter = radius * 2.0f;
	float circunference = 2.0f * pi * radius;
	float area = pi * radius * radius;

	printf("The diameter of the triangle is %2.2f\n", diameter);
	printf("The circunference of the triangle is %2.2f\n", circunference);
	printf("The area of the triangle is %2.2f\n", area);

	return 0;
}