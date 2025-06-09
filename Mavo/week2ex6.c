/*
 * week2ex6.c
 *
 *  Created on: May 31, 2025
 *      Author: user
 */

#include <stdio.h>
#include <math.h>

int main(){
	int i = 1;
	double d = 1;
	int x, y;

	/** Enter your code here
	xxxxxxxxxxxxxxxxxx
	*/
	i = (i+6)/7;
	printf("%d\n", i);
	i = i-7;
	printf("%d\n", i);
	i = 2.2 / 1.5;
	printf("%d\n", i);
	d = 42.0;
	printf("%f\n", d);
	d = d + i/1000;
	printf("%f\n", d);
	d = 0;d--;
	printf("%f\n", d);
	d = 0.5;
	printf("%f\n", d);
	i = (d != 5) + d;
	printf("%d\n", i);
	d = 144;
	i = 12.5;
	x = sqrt(d) >= pow(i, 2.0);
	printf("Your boolean variable is: %s\n", x ? "true" : "false");
	d = (i-2) && (8 * 2.3);
	printf("%f\n", d);
	d = i || i;
	printf("%f\n", d);
	x = i--;
	printf("%d\n", x);
	y = --i;
	printf("%d\n", y);
	x = 0, y = 5;
	printf("%d\n", x);
	i = (x = y);
	printf("%d\n", i);
	return 0;
}
