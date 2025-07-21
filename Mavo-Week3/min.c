/*
 * min.c
 *
 *  Created on: Jul 10, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int n, min;
	printf("Enter positive numbers:\n");
	scanf("%d", &n);
	min = n;
	while(n > 0){
		scanf("%d", &n);
		if(n < 0)
			break;
		if(n < min)
			min = n;
	}
	printf("Min: %d\n", min);
	return 0;
}


