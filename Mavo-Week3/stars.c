/*
 * stars.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */

#include <stdio.h>

#define N 7

int main(){
	int i, j;
	for(i = 0;i < N;i++){
		for(j = 0;j < i;j++)
			printf("*");
		printf("\n");
	}

	return 0;
}


