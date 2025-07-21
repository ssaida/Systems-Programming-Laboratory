/*
 * average.c
 *
 *  Created on: Jul 8, 2025
 *      Author: user
 */

#include <stdio.h>

#define MAX_INPUT 10

int main(void){
	double x, sum, avrg;
	int c = 0;
	sum = 0;

	while(c < MAX_INPUT){
		scanf("%lf", &x);
		sum += x;
		c++;
	}
	avrg = sum / MAX_INPUT;
	printf("The average: %f\n", avrg);
	return 0;
}


