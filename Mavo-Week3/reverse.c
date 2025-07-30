/*
 * reverse.c
 *
 *  Created on: Jul 30, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int num, reverse = 0;

	printf("Enter a number to calculate reverse:\n");
	scanf("%d", &num);

	while(num > 0){
		reverse = reverse * 10 + num % 10;
		num /= 10;
	}
	printf("In reverse: %d", reverse);
	return 0;
}



