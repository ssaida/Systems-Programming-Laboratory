/*
 * while.c
 *
 *  Created on: Jun 3, 2025
 *      Author: user
 */


#include <stdio.h>

int main(){
	double x, sum, average;
	int c = 0;
	sum = 0;
	while(c < 5){
		printf("Enter a number\n");
		scanf("%lf", &x);
		sum += x;
		c++;
	}
	average = sum / 5;
	printf("Sum: %f\n", sum);
	printf("Average: %f\n",average);
	return 0;
}
