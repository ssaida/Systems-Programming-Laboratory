/*
 * sum2numbers.c
 *
 *  Created on: May 27, 2025
 *      Author: user
 */

#include<stdio.h>

int main(){
	int num1, num2;

	printf("Enter two numbers:\n");
	scanf("%d %d\n", &num1, &num2);

	printf("Sum of the two numbers: %d\n", num1 + num2);
	printf("Average of the two numbers %d\n", (num1+num2) / 2);

	return 0;

}
