/*
 * calc.c
 *
 *  Created on: Jul 24, 2025
 *      Author: user
 */

#include <math.h>
#include "data.h"


int findLargest(int a[]){
	int i, max = a[0];
	for(i = 1;i < size;i++)
		if(a[i] >max)
			max = a[i];
	return pow(max, pw);
}

