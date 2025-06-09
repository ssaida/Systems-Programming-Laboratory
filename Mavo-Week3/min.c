/*
 * min.c
 *
 *  Created on: Jun 4, 2025
 *      Author: user
 */

#include <stdio.h>

int main(void){
	int num, min = 0;
	printf("Enter a number:\n");
	scanf("%d", &num);

	while(num < 0){
		if (num > min)
			min = num;
		printf("Enter another number:\n");
		scanf("%d", &num);
	}
	printf("Min number is: %d", min);

	return 0;
}
