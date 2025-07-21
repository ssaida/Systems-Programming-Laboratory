/*
 * parallelogram.c
 *
 *  Created on: Jul 10, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int size, i, j, k;
	char ch = 'A';

	printf("Enter a size of parallelogram ( 1 - 26):\n");
	scanf("%d", &size);
	if(size < 1 && size > 26){
		printf("Size input error!\n");
		return 1;
	}

	for(i = 0;i <= size;i++){
		for(j = 0;j < i;j++){
			printf(" ");
		}
		for(k = 0;k <= size;k++){
			printf("%c", ch);
		}
		ch++;
		printf("\n");
	}
	return 0;
}



