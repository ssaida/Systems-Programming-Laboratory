/*
 * temperature.c
 *
 *  Created on: May 29, 2025
 *      Author: user
 */
#include <stdio.h>

int main(){
	int cel_temp, fahr_temp;
	fahr_temp = 34;

	cel_temp = (fahr_temp - 32) / (212 - 32) * 100;

	printf("Celsius: %d, Fahrenhite %d\n", cel_temp,fahr_temp);

	return 0;
}

