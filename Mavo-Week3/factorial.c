/*
 * factorial.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int i, num, fact = 1;

	printf("Enter a number to calculate factorial:\n");
	scanf("%d", &num);
	if(num < 0){
		printf("Negative number! cannot calculate factorial\n");
		return 1;
	}

	for(i = 1;i <= num;i++){
		fact *= i;
	}
	printf("Factorial for %d is %d", num, fact);
	return 0;
}
