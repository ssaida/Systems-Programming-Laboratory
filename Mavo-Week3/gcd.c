/*
 * gcd.c
 *
 *  Created on: Jul 29, 2025
 *      Author: user
 */

#include <stdio.h>

int main(){
	int m, n, r;

	printf("Enter two numbers to calculate GCD:\n");
	scanf("%d, %d", &n, &m);

	if(m < n){
		r = m;
		m = n;
		n = r;
	}
	while(n > 0){
		r = m % n;
		m = n;
		n = r;
	}

	printf("Gcd: %d", m);
	return 0;

}


