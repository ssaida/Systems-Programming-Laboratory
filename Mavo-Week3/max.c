/*
 * max.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	double a, b, c, d;
	double max;

	printf("Enter 4 numbers:\n");
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	if(a > b)
		max = a;
	else
		max = b;
	if(c > max)
		max = c;
	if(d > max)
		max = d;

	printf("Max: %f\n", max);

	return 0;
}



