/*
 * average.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	double num, sum = 0, avg;
	int count = 0;

	while(count < 5){
		scanf("%lf", &num);
		sum += num;
		count++;
	}
	avg = sum / count;
	printf("Average: %f", avg);
	return 0;
}
