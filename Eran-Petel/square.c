/*
 * square.c
 *
 *  Created on: Jun 28, 2025
 *      Author: user
 */
#include <stdio.h>

#define SQUARE(X) (X) * (X)
#define MAX(A,B) (A)>(B)?(A):(B)

int main(){
	int a = 3;
	int b = 5;
	int aAndBSquared;
	int aSquared;
	int maxAB;
	float c = 4.5;
	float d = 2.5;
	float maxCD;
	float max;
	aAndBSquared = SQUARE(a+b);
	aSquared = SQUARE(a);
	maxAB = MAX(a, b);
	maxCD = MAX(c, d);
	max = MAX(a+b, c+d);

	printf("aAndBSquared: %d\n", aAndBSquared);
	printf("aSquared: %d\n", aSquared);
	printf("maxAB: %d\n", maxAB);
	printf("maxCD: %f\n", maxCD);
	printf("%f\n", max);
	/* Hello */
	return 0;
}
