/*
 * ex4.c
 *
 *  Created on: Jul 28, 2025
 *      Author: user
 */

#include <stdio.h>
#include <math.h>

int main()
{
	int number;

	printf("Enter a number between 0 - 1000000:\n");
	scanf("%d", &number);

	printf("Power of %d is %.f\n", number, pow(number, 2));

    return 0;
}
