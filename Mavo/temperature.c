/*
 * temperature.c
 *
 *  Created on: Jun 29, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int cel_temp, fahr_temp;

	printf("Enter the temperature in a fehrenhite: ");
	scanf("%d", &fahr_temp);

	cel_temp = (fahr_temp - 32) * 100 / (212 - 32);
	printf("Temperature in Celsius: %d\nTemperature in Fehrenhite: %d\n", cel_temp, fahr_temp);

	return 0;
}
