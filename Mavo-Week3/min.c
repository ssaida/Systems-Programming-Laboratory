/*
 * min.c
 *
 *  Created on: Jul 30, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int num, min;
	printf("Enter a number:");
	scanf("%d", &num);
	min = num;
	while(num > 0){
		printf("Enter another number:");
			scanf("%d", &num);
			if(num == 0)
				break;
			if(num < min)
				min = num;
	}

	printf("Minimum number is: %d\n", min);
	return 0;
}


