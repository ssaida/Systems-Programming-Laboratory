/*
 * palindrome.c
 *
 *  Created on: Jul 10, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int num, pal=0;
	printf("Enter a number to calculate Palindrome:\n");
	scanf("%d", &num);

	if(num < 0){
		printf("Invalid input\n");
		return 1;
	}


	while(num > 0){
		pal = pal * 10 + num % 10;
		num /= 10;
	}

	printf("Palindrome is:%d\n",pal);
	return 0;
}


