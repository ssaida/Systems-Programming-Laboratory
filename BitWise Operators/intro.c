/*
 * intro.c
 *
 *  Created on: Jul 5, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){

	int a = 1101;
	int b = 0x123;
	int c = 045;
	int d = 32467;
	int o = 23471;

	printf("a: %d\nb: %d\nc: %d\nd: %d\n", a, b, c, d);
	printf("%d\n", a);
	printf("%o\n", a);
	printf("%x\n", a);
	printf("%c\n", a);
	printf("Print in Octal:\n");
	printf("%o\n", o);
	printf("Print in Decimal:\n");
	printf("%d\n", o);

	return 0;
}



