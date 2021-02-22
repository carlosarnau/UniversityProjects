// 16. Write a program that computes your final mark given several marks

#include <stdio.h>		// Required for: printf(), scanf()

int main()
{
	float partial_exam = 0;
	float final_exam = 0;
	float exercise1 = 0;
	float exercise2 = 0;
	float exercise3 = 0;
	float exercise4 = 0;

	printf("Introduce the mark of your partial exam: ");
	scanf_s("%f", &partial_exam);

	printf("Introduce the mark of your final exam: ");
	scanf_s("%f", &final_exam);

	printf("Introduce the mark of your first class exercise: ");
	scanf_s("%f", &exercise1);

	printf("Introduce the mark of your second class exercise: ");
	scanf_s("%f", &exercise2);

	printf("Introduce the mark of your third class exercise: ");
	scanf_s("%f", &exercise3);

	printf("Introduce the mark of your third class exercise: ");
	scanf_s("%f", &exercise4);

	float class_exercises = (exercise1 + exercise2 + exercise3 + exercise4) / 4;
	float final_mark = (partial_exam * 0.30f) + (class_exercises * 0.40f) + (final_exam * 0.30f);
	
	printf("Your final mark of the semester is %2.2f", final_mark);

	return 0;
}
