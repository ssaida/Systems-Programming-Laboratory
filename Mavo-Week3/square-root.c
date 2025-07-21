/*
 * square-root.c
 *
 *  Created on: Jul 8, 2025
 *      Author: user
 */

#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c;
	double x1, x2;
	double disc;

	printf("Enter the coefficients (a b and c):\n");
	scanf("%lf %lf %lf", &a, &b, &c);
	disc = b * b - 4 * a * c;
	if(disc >= 0){
		x1 = (-b + sqrt(disc)) / 2 * a;
		x2 = (-b - sqrt(disc)) / 2 * a;
		printf("The roots of the equation are: %f %f\n", x1, x2);
	}else{
		printf("Disc is less than 0, cannot be divided\n");
	}

	return 0;
}
