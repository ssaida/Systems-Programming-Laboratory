/*
 * size.c
 *
 *  Created on: Jul 30, 2025
 *      Author: user
 */

#include <stdio.h>

#define N 10

int main(){
	char ch = 'A';
	int i, j, k;
	for(i = 0;i < N;i++){
		for(j = 0;j < i;j++){
			printf(" ");
		}
		for(k = 0;k < N;k++){
			printf("%c", ch);
		}
		ch++;
		printf("\n");
	}

	return 0;
}
