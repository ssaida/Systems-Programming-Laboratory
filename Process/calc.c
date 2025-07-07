/*
 * calc.c
 *
 *  Created on: Jun 22, 2025
 *      Author: user
 */
#include <math.h>
#include "data.h"



int findLargest(int a[]){
	int i, max = a[0];
	for(i = 1;i<SIZE;i++)
		max = (a[i] > max) ? a[i] : max;
	return pow(max, PW);
}

