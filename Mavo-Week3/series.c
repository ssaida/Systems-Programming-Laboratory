/*
 * series.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int n, a_n, i;

	printf("Enter a positive number: \n");
	scanf("%d", &n);

	if(n < 0){
		printf("Must be a positive number:\n");
		return 1;
	}

	if(n == 0){
		a_n = 3;
	}else{
		a_n = 3;
		for(i = 1;i <= n;i++){
			a_n = 3 * a_n + 4;
		}
	}

	printf("%d : %d\n", n, a_n);

	return 0;
}


