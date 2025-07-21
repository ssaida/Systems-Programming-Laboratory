/*
 * stars.c
 *
 *  Created on: Jul 10, 2025
 *      Author: user
 */

#include <stdio.h>

#define MAX 10

int main(){
	int i, j, k;
	for(i = 0; i <= MAX; i++){
		for(j = 0;j<=i;j++){
			for(k=0;k<=j;k++){
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}



	return 0;
}


