/*
 * factorial.c
 *
 *  Created on: Jun 1, 2025
 *      Author: user
 */

#include <stdio.h>
#include <ctype.h>

long int factorial(int);

int main(void){

	int i = 0;
	long int j;
	int c;

	printf("Please enter a number:\n");
	while(isdigit(c = getchar()))
		i = i * 10 + c - '0';

	printf("Factorial of %d is %ld\n", i, j=factorial(i));
	printf("Double factorial of %d is %ld\n", i, 2*j);
	printf("The value of %ld is %s\n", j, (j%2) ? "Odd" : "Even");
	return 0;
}
long int factorial(int n){
	if(n)
		return(n * factorial(n-1));
	else
		return 1;
}
