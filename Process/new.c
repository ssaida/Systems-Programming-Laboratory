/*
 * prog.c
 *
 *  Created on: Jun 22, 2025
 *      Author: user
 */

#include <stdio.h>
#include "data.h"



int findLargest(int []);
void getNumbers(int []);

int main(){
	int arr[SIZE] = {0};
	int res;

	printf("\n Program input : an array of %d integers. \n", SIZE);
	printf("\n Program output: max number in array raised by %d", PW);

	getNumbers(arr);
	res = findLargest(arr);

	printf("\n the result is: %d\n", res);
	return 0;
}

void getNumbers(int a[]){
	int i;
	printf("Enter %d numbers to fill the array:\n", SIZE);
	for(i = 0;i < SIZE;i++)
		scanf("%d", a+i);
}

