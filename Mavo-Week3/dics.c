/*
 * dics.c
 *
 *  Created on: Jul 28, 2025
 *      Author: user
 */

#include <stdio.h>
#include <math.h>

int main(){
	double a, b, c;
	double x1, x2;
	double dics;

	printf("Enter a parameters of the equation:\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	dics = pow(b, 2) - 4 * a * c;
	if(dics >= 0){
		x1 = (-b + sqrt(dics)) / (2 * a);
		x2 = (-b - sqrt(dics)) / (2 * a);
		printf("The roots of the equation are: %f, %f\n", x1, x2);
	}else{
		printf("There is no roots for the equation!\n");
	}


	return 0;
}
