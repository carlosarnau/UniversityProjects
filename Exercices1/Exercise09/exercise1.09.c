// 09. Write a program that asks for 2 angles of a triangle and find the third angle.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float angle01 = 0;
	float angle02 = 0;

	printf("Introduce an angle: ");
	scanf_s("%f", &angle01);

	printf("Introduce another angle: ");
	scanf_s("%f", &angle02);

	float angle03 = 360.0f - (angle01 + angle02);

	printf("The thrid angle of the triangle is %2.2f\n", angle03);
	
	return 0;
}