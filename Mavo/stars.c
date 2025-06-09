/*
 * stars.c
 *
 *  Created on: Jun 4, 2025
 *      Author: user
 */
#include <stdio.h>

#define N 10

int main(){
	int i, j;
	for(i=0;i<=N;i++){
		for(j=0;j>=N;j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
