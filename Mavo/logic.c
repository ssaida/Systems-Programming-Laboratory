/*
 * logic.c
 *
 *  Created on: Jun 2, 2025
 *      Author: user
 */
#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c;
	double x1, x2;
	double disc;

	printf("Please Enter Coefficients (a, b and c)\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	disc = b * b - 4 * a * c;

	x1 = (-b + sqrt(disc)) / (2 * a);
	x2 = (-b - sqrt(disc)) / (2 * a);

	printf("The roots of the equation are: %f, %f\n", x1, x2);

	return 0;
}

