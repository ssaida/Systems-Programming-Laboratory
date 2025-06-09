#include <stdio.h>

int main()
{
	int num1, num2, num3;
	int sum;


	printf("Please enter 3 numbers separated by spaces:\n\n");
	scanf("%d %d %d", &num1, &num2, &num3);

	sum = num1 + num2 + num3;

	printf("The sum of the numbers is: %d\n", sum);
	printf("The average of the numbers is: %f\n", sum/3.0);
	return 0;
}
