/*
 * printfAboveAverage.c
 *
 *  Created on: Jul 12, 2025
 *      Author: user
 */

#include <stdio.h>

#define RANGE 4

int main(){
	int i, sum = 0;
	double avrg;

	int arr[RANGE] = {21, 7, 3, 9};

	for(i = 0;i < RANGE;i++){
		sum += arr[i];
	}
	avrg = sum / RANGE;

	printf("Average: %f\n", avrg);
	printf("Numbers above average: \n");

	for(i = 0;i < RANGE;i++){
		if(arr[i] > avrg)
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

