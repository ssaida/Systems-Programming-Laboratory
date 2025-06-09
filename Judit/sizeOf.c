/*
 * sizeOf.c
 *
 *  Created on: May 29, 2025
 *      Author: user
 */
#include <stdio.h>
int main(){
	char c = 'a';
	int i = 10;
	double d = 3.14;
	float f = 642874682.2;

	printf("Size Of char : %d\n", sizeof(c));
	printf("Size Of char : %d\n", sizeof(char));
	printf("Size Of int : %d\n", sizeof(i));
	printf("Size Of char : %d\n", sizeof(int));
	printf("Size Of double : %d\n", sizeof(d));
	printf("Size Of char : %d\n", sizeof(double));
	printf("Size Of float : %d\n", sizeof(f));
	printf("Size Of char : %d\n", sizeof(float));

	return 0;
}
