/*
 * sort.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int num1, num2, num3;

	printf("Enter 3 numbers to sort:\n");
	scanf("%d %d %d", &num1, &num2, &num3);

	if(num1 < num2 && num1 < num3){
		if(num2 < num3){
			printf("Sort by smaller to bigger: %d %d %d\n", num1, num2, num3);
		}else{
			printf("Sort by smaller to bigger: %d %d %d\n", num1, num2, num3);
		}
	}

	else if(num2 < num1 && num2 < num3){
		if(num1 < num3){
			printf("Sort by smaller to bigger: %d %d %d\n", num2, num1, num3);
		}else{
			printf("Sort by smaller to bigger: %d %d %d\n", num2, num3, num1);
		}
	}

	else if(num3 < num1 && num3 < num2){
		if(num2 < num1){
			printf("Sort by smaller to bigger: %d %d %d\n", num3, num2, num1);
		}else{
			printf("Sort by smaller to bigger: %d %d %d\n", num3, num1, num2);
		}
	}
	return 0;
}
