/*
 * series.c
 *
 *  Created on: Jun 4, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int n, i;
	long an;

	printf("Enter a positive number:\n");
	if(scanf("%d", &n) != 1){
		printf("Invalid input\n");
		return 0;
	}

	if(n < 0){
		return 0;
	}

	if(n == 0){
		an = 3;
	}else{
		an = 3;
		for(i = 1;i <= n;i++){
			an = 3 * an + 4;
		}
	}
	printf("a%d = %ld\n", n, an);
	return 0;
}
