/*
 * factorial.c
 *
 *  Created on: Jun 3, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int i, factorial=1, number;

	printf("Enter a number to calculate factorial\n");
	scanf("%d", &number);

	if(number < 0)
			number *= -1;

	for(i = 1;i <= number;i++){
		factorial *= i;
	}
	printf("Factorial for %d id %d\n", number, factorial);

	return 0;
}

