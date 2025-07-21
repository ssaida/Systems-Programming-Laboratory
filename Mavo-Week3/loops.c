/*
 * loops.c
 *
 *  Created on: Jul 9, 2025
 *      Author: user
 */

#include <stdio.h>
#define FACTORIAL 5
int main(){
	int x, fact=1, i ,j;
	do{
		printf("Enter a number:\n");
		scanf("%d", &x);
	}while(x <= 0);
	printf("x: %d\n", x);
	printf("Count to 10\n");
	printf("While:\n");
	x = 0;
	while(x <= 10){
		printf("%d ", x);
		x++;
	}
	printf("\nDo - While:\n");
	x = 0;
	do{
		printf("%d ", x);
		x++;
	}while(x <= 10);
	printf("\nFor:\n");
	for(x = 0;x <= 10;x++){
		printf("%d ", x);
	}
	printf("Factorial:\n");
	for(x = 1;x < FACTORIAL;x++){
		fact *= x;
	}
	printf("Factorial for %d is %d\n", FACTORIAL, fact);
	printf("Muliple:\n");
	for(i = 1;i <= 10;i++){
		for(j = 1;j <= i;j++){
			printf("%d\t", i*j);
		}
		printf("\n");
	}
	return 0;
}

