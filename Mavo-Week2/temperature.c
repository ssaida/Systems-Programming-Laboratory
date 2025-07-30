/*
 * temperature.c
 *
 *  Created on: Jul 26, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int cel_temp, fahr_temp;

	printf("Enter a fahrenheit temperature:\n");
	scanf("%d", &fahr_temp);

	cel_temp = (fahr_temp - 32) * 100 / (212 - 32);

	printf("Temperature in fahrenheie: %d and in celcius: %d\n", fahr_temp, cel_temp);

	return 0;
}


