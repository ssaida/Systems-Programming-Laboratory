/*
 * prog.c
 *
 *  Created on: Jul 24, 2025
 *      Author: user
 */

#include <stdio.h>
#include "data.h"

int findLargest(int []);
void getNumbers(int []);

int main(){

	int arr[size] = {0};
	int res;
	printf("Program input: an array of %d integers.\n", size);
	printf("Program output: max number in array raised by %d\n", pw);

	getNumbers(arr);
	res = findLargest(arr);
	printf("The largest number is: %d\n",res);
	return 0;
}

void getNumbers(int a[]){
	int i;
	printf("Enter %d Numbers\n", size);
	for(i = 0;i < size;i++)
		scanf("%d", a+i);
}
