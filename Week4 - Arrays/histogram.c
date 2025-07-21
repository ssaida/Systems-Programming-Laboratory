/*
 * histogram.c
 *
 *  Created on: Jul 12, 2025
 *      Author: user
 */

#include <stdio.h>

#define NUM_STUDENTS 1000
int main(){
	int i;
	int grades[NUM_STUDENTS];
	int hist[101] = { 0 };

	for (i = 0; i < NUM_STUDENTS; i++){
		scanf("%d", &grades[i]);
	}

	for (i = 0; i < NUM_STUDENTS; i++){
		int g = grades[i];
		hist[g]++;
	}
	return 0;
}
