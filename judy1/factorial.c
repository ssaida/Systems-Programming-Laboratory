/*
 * factorial.c
 *
 *  Created on: Jul 23, 2025
 *      Author: user
 */
#include <stdio.h>

int factorial(int);

int main(){
	int n;
	printf("Enter a number to calculate factorial:\n");
	scanf("%d", &n);

	printf("Factorial is: %d\n", factorial(n));
	return 0;
}
int factorial(int number){
	int i, fact =1;
	for(i = 1;i <= number;i++){
		fact *= i;
	}
	return fact;
}
