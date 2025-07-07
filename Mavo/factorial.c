/*
 * factorial.c
 *
 *  Created on: Jun 30, 2025
 *      Author: user
 */
#include <stdio.h>

int factorial(int);

int main(){
	int n;
	printf("Enter a number to calculate factorial:\n");
	scanf("%d", &n);

	printf("Factorial for %d is %d\n", n, factorial(n));

	return 0;
}

int factorial(int n){
	int i, factorial=1;
	for(i=1;i<n;i++){
		printf("%d\n", factorial);
		factorial *= i;
	}
	return factorial;
}

