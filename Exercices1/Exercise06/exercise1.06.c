// 06. Write a program that asks for rectangle width and height and compute area and perimeter.

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	int width = 0;
	int height = 0;

	printf("Introduce the width of the rectangle: ");
	scanf_s("%i", &width);

	printf("Introduce the height of the rectangle: ");
	scanf_s("%i", &height);

	int area = width * height;
	int perimeter = perimeter = width * height;

	printf("The area of the rectangle is %i\n", area);
	printf("And the perimeter of the rectangle is %i\n", perimeter);

	return 0;
}