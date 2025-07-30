/*
 * stars1.c
 *
 *  Created on: Jul 29, 2025
 *      Author: Samer Saida
 */

#include <stdio.h>

#define N 7

int main(){
	int i, j;
	for(i = 0;i <= N;i++){
		for(j = N;j >= i;j--){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}


