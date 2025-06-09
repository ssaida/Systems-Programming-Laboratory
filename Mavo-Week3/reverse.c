/*
 * reverse.c
 *
 *  Created on: Jun 4, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int num;
	int hondered, tens, onse=0;

	printf("Enter a number\n");
	scanf("%d", &num);

	hondered = num % 100;
	num /= 100;
	tens = num % 10;
	num /= 10;
	onse += num;
	printf("%d%d%d\n", onse, tens, hondered);

	return 0;
}
